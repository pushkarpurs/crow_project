// model.hpp
#pragma once
#include <string>
#include <unordered_map>
#include <optional>
#include <iostream>
#include <array>
#include <memory>

#ifdef _WIN32
#define popen _popen
#define pclose _pclose
#endif

struct User {
    std::string username;
    std::string password;
    std::string role;
    bool loggedIn = false;
};

class UserModel {
	private:
    
	std::unordered_map<std::string, User> users;
	std::string usn = "";
	// const std::string chat_file = "E:/Pushkar/SEM 6/OOAD/crow_project/chat.txt";
	const std::string chat_file = "chat.txt";
	std::mutex file_mutex;

	public:
    
	UserModel() {
        users["admin"] = {"admin", "admin123", "admin", false};
        users["trader"] = {"trader", "trader123", "trader", false};
    }

    int login(const std::string& username, const std::string& password) {
		std::cout<<"In model.login"<<username<<" - "<<password<<std::endl;
        if(users.count(username) && users[username].password==password && usn=="")
		{
			users[username].loggedIn=true;
			usn=username;
			return 0;
		}
        if(users.count(username)==0 || users[username].password!=password)
			return 1;
		return 2;
		
    }
	
	int signup(const std::string& username, const std::string& password) {
        if(users.count(username)==0 && usn=="")
		{
			users[username] = {username, password, "trader", true};
			usn=username;
			return 0;
		}
		if(users.count(username)!=0)
			return 1;
        return 2;
    }


    void logout() {
        users[usn].loggedIn=false;
		usn="";
    }

    std::optional<User> getUser() {
		std::cout<<"In get user"<<std::endl;
        if (users.count(usn)) return users[usn];
        return std::nullopt;
    }
	
	
	//Dont change this function
	std::string askLLM(const std::string& input) {
		// std::string command = "python callllm.py \"" + input + "\"";
		// std::array<char, 256> buffer;
		// std::string result_output;
		// bool result_section_started = false;

		// std::shared_ptr<FILE> pipe(popen(command.c_str(), "r"), pclose);
		// if (!pipe) {
			// throw std::runtime_error("Failed to run Python script.");
			// return "Error";
		// }

		// while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
			// std::string line(buffer.data());

			// if (!result_section_started && line.find("RESULT:") == 0) {
				// result_section_started = true;
			// }

			// if (result_section_started) {
				// result_output += line;
			// }
		// }

		// return result_output;
		
		return "Fosho you should invest in "+input;
	}
	
    bool isLoggedIn(const std::string& username) {
        return users.count(username) && users[username].loggedIn;
    }
	
	std::string urlDecode(const std::string& encoded) {
		std::string decoded;
		char ch;
		int i, ii;
		for (i = 0; i < encoded.length(); i++) {
			if (encoded[i] == '%') {
				if (i + 2 < encoded.length()) {
					std::istringstream iss(encoded.substr(i + 1, 2));
					if (iss >> std::hex >> ii) {
						ch = static_cast<char>(ii);
						decoded += ch;
						i += 2;
					} else {
						decoded += '%'; // fallback in case of bad encoding
					}
				}
			} else if (encoded[i] == '+') {
				decoded += ' ';
			} else {
				decoded += encoded[i];
			}
		}
		return decoded;
	}
	
	std::string chatUpdate(const std::string& message)
	{
		auto msg=urlDecode(message);
		if(msg!="")
		{
			msg=usn+" : "+msg;
			std::unique_lock<std::mutex> lock(file_mutex);
			std::ofstream out(chat_file, std::ios::app);
			out << msg << "\n";
			lock.unlock();
		}
		return chatRead();
	}
	
	std::string chatRead()
	{
		std::unique_lock<std::mutex> lock(file_mutex);

		std::ifstream in(chat_file);
		std::ostringstream chat_content;
		std::string line;

		while (std::getline(in, line)) {
			chat_content << line << "<br/>";
		}

		return chat_content.str();
	}
};
