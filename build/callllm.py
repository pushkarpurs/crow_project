import sys
import google.generativeai as genai
import requests
from bs4 import BeautifulSoup
from serpapi import GoogleSearch
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity
import re
import time
from sentence_transformers import SentenceTransformer, util

def get_clean_text_from_url(url):
    time.sleep(2)
    try:
        response = requests.get(url, timeout=5)
        soup = BeautifulSoup(response.content, 'html.parser')
        for script in soup(["script", "style"]):
            script.extract()
        text = soup.get_text(separator=' ')
        text = re.sub(r'\s+', ' ', text)
        return text.strip()
    except:
        return ""

def chunk_text(text, chunk_size=50):
    words = text.split()
    return [' '.join(words[i:i+chunk_size]) for i in range(0, len(words), chunk_size)]

def get_top_chunks(query, serpapi_api_key, max_sites=5, chunk_size=50, top_n=3):
    # Use SerpApi to get search results
    search = GoogleSearch({
        "q": query,
        "api_key": serpapi_api_key,
        "num": max_sites
    })
    results = search.get_dict()
    urls = [result['link'] for result in results.get('organic_results', [])]

    all_chunks = []

    for url in urls:
        text = get_clean_text_from_url(url)
        if text:
            chunks = chunk_text(text, chunk_size=chunk_size)
            all_chunks.extend(chunks)

    if not all_chunks:
        return []

    model = SentenceTransformer('all-MiniLM-L6-v2')

    # Encode query and chunks into dense vector representations
    query_embedding = model.encode(query, convert_to_tensor=True)
    chunk_embeddings = model.encode(all_chunks, convert_to_tensor=True)

    # Compute cosine similarities
    cosine_scores = util.cos_sim(query_embedding, chunk_embeddings)[0]

    # Get top N chunk indices
    top_indices = cosine_scores.argsort(descending=True)[:top_n]

    # Return the top matching chunks
    top_chunks = [all_chunks[i] for i in top_indices]
    return top_chunks

def call_gemini(question):
    genai.configure(api_key="")  # 🔑 Replace with your Gemini API key
    
    serpapi_api_key = "" # 🔑 Replace with your SERP API key
    query = "has the "+question+" stock been performing positively or negatively"
    top_chunks = get_top_chunks(query, serpapi_api_key)
    
    for i in range(3):
        print("Chunk ",i,"  ------------------------------")
        print(top_chunks[i])
    
    question= "Using only the below information"+top_chunks[0]+""+top_chunks[1]+""+top_chunks[2]+" is "+question+" stock a buy sell or wait and watch"
    
    print("Question -------------------------------")
    print(question)
    
    print(f"RESULT: ")
    
    model = genai.GenerativeModel("gemini-2.0-flash")

    try:
        response = model.generate_content(question)
        print(response.text.strip())
    except Exception as e:
        print("Error:", str(e))

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("No input provided.")
    else:
        question = sys.argv[1]
        call_gemini(question)
