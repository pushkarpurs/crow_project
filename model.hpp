// model.hpp
#pragma once
#include <string>
#include <unordered_map>
#include <optional>
#include <iostream>
#include <array>
#include <memory>
#include <vector>

#ifdef _WIN32
#define popen _popen
#define pclose _pclose
#endif

struct Transaction {
    std::string stock;
    int quantity;
    double price; // Price at the time of purchase.
};
struct User {
    std::string username;
    std::string password;
    std::string role;
    bool loggedIn = false;
    std::vector<Transaction> transactions;
    std::unordered_map<std::string, std::pair<int, double>> holdings;
    std::unordered_map<std::string, double> profits;
    double overallProfit = 0.0;  // New: overall profit updated after each sell transaction
};

class UserModel {
	private:
    
	std::unordered_map<std::string, User> users;
	std::string usn = "";
	const std::string chat_file = "E:/Pushkar/SEM 6/OOAD/OOAD_Project/crow_project/chat.txt";
	std::mutex file_mutex;
	 // Hardcoded stocks with prices to simulate the market
	 // Add this as a private member variable in the UserModel class
	const std::string log_file = "E:/Pushkar/SEM 6/OOAD/OOAD_Project/crow_project/logs.txt";
	std::mutex log_mutex;

	public:
    
	UserModel() {
        users["admin"] = {"admin", "admin123", "admin", false};
        users["trader"] = {"trader", "trader123", "trader", false};
    }
	public:
	std::string getPortfolioInfo() {
		if (usn.empty())
			return "User not logged in.";
		std::ostringstream oss;
		const auto& user = users[usn];
		oss << "<ul>";
		for (const auto& [stock, holding] : user.holdings) {
			int shares = holding.first;
			double totalCost = holding.second;
			// Only display stocks with positive holdings.
			if (shares > 0) {
				double profit = 0.0;
				if (user.profits.find(stock) != user.profits.end())
					profit = user.profits.at(stock);
				oss << "<li>" 
					<< stock 
					<< ": " << shares << " shares, Total Cost: $" 
					<< std::fixed << std::setprecision(2) << totalCost 
					<< ", Profit: $" << std::fixed << std::setprecision(2) << profit 
					<< "</li>";
			}
		}
		oss << "</ul>";
		oss << "<p><strong>Overall Profit: $" 
			<< std::fixed << std::setprecision(2) << user.overallProfit 
			<< "</strong></p>";
		return oss.str();
	}
	std::unordered_map<std::string, double> stocks {
        {"AAPL", 150.34},
        {"GOOGL", 2695.56},
        {"AMZN", 3445.23},
        {"MSFT", 299.79},
        {"TSLA", 720.20},
        {"NFLX", 590.65},
        {"NVDA", 220.14},
        {"ADBE", 620.60},
        {"INTC", 52.34},
        {"CSCO", 56.78},
        {"ORCL", 85.99},
        {"IBM", 139.23},
        {"CRM", 243.34},
        {"PYPL", 299.01},
        {"TWTR", 58.65},
        {"UBER", 45.12},
        {"SQ", 252.50},
        {"SHOP", 1224.90},
        {"SNAP", 18.25},
        {"AMD", 95.12}
    };

	bool buyStock(const std::string& stockSymbol, int quantity) {
		if (usn.empty()) {
			std::cout << "User not logged in. Cannot buy stock." << std::endl;
			return false;
		}
		if (stocks.find(stockSymbol) == stocks.end()) {
			std::cout << "Stock symbol " << stockSymbol << " not found." << std::endl;
			return false;
		}
		double currentPrice = stocks[stockSymbol];
		users[usn].transactions.push_back({stockSymbol, quantity, currentPrice});
		// Update holdings: add the shares and cost basis.
		auto& h = users[usn].holdings[stockSymbol];
		h.first += quantity;                    // increase share count
		h.second += quantity * currentPrice;     // increase total cost
		std::cout << "User " << usn << " bought " << quantity << " shares of " 
				  << stockSymbol << " at $" << currentPrice << " per share." << std::endl;
		std::unique_lock<std::mutex> lock(log_mutex);
		std::ofstream out(log_file, std::ios::app);
		out << "User " << usn << " bought " << quantity << " shares of " 
				  << stockSymbol << " at $" << currentPrice << " per share." << std::endl;
		lock.unlock();
		return true;
	}
	std::string getStocks() {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<double> dis(-5.0, 5.0);
		
		std::ostringstream oss;
		for (auto& [stock, price] : stocks) {
			 double change = dis(gen);
			 price += change;
			 oss << stock << ": $" << std::fixed << std::setprecision(2) << price << "<br/>";
		}
		return oss.str();
	}

	bool sellStock(const std::string& stockSymbol, int quantity) {
		if (usn.empty()) {
			std::cout << "User not logged in. Cannot sell stock." << std::endl;
			return false;
		}
		if (stocks.find(stockSymbol) == stocks.end()) {
			std::cout << "Stock symbol " << stockSymbol << " not found." << std::endl;
			return false;
		}
		auto& h = users[usn].holdings[stockSymbol];
		if (h.first < quantity) {
			std::cout << "User " << usn << " does not have enough shares of " 
					  << stockSymbol << " to sell." << std::endl;
			return false;
		}
		double currentPrice = stocks[stockSymbol];
		// Calculate average cost per share.
		double averageCost = h.second / h.first;
		// Profit for this sale.
		double profitForSale = (currentPrice - averageCost) * quantity;
		// Record the sale in transactions (using negative quantity).
		users[usn].transactions.push_back({stockSymbol, -quantity, currentPrice});
		// Update holdings: reduce share count and cost basis.
		h.first -= quantity;
		h.second -= averageCost * quantity;
		// Accumulate profit per stock and overall.
		users[usn].profits[stockSymbol] += profitForSale;
		users[usn].overallProfit += profitForSale;  // update overall profit
		std::cout << "User " << usn << " sold " << quantity << " shares of " 
				  << stockSymbol << " at $" << currentPrice 
				  << " per share, realizing a profit of $" << profitForSale << std::endl;
		std::unique_lock<std::mutex> lock(log_mutex);
		std::ofstream out(log_file, std::ios::app);
		out << "User " << usn << " sold " << quantity << " shares of " 
				  << stockSymbol << " at $" << currentPrice 
				  << " per share, realizing a profit of $" << profitForSale << std::endl;
		lock.unlock();
		return true;
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
		std::string command = "python callllm.py \"" + input + "\"";
		std::array<char, 256> buffer;
		std::string result_output;
		bool result_section_started = false;

		std::shared_ptr<FILE> pipe(popen(command.c_str(), "r"), pclose);
		if (!pipe) {
			throw std::runtime_error("Failed to run Python script.");
			return "Error";
		}

		while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
			std::string line(buffer.data());

			if (!result_section_started && line.find("RESULT:") == 0) {
				result_section_started = true;
			}

			if (result_section_started) {
				result_output += line;
			}
		}

		return result_output;
		
		//return "Fosho you should invest in "+input;
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
	
	std::string getLogs()
	{
		if(users[usn].role!="admin")
		{
			return "You do not have permission to read logs";
		}
		std::unique_lock<std::mutex> lock(log_mutex);

		std::ifstream in(log_file);
		std::ostringstream chat_content;
		std::string line;

		while (std::getline(in, line)) {
			chat_content << line << "<br/>";
		}

		return chat_content.str();
	}
};
