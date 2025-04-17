// controller.hpp
#pragma once
#include <crow/app.h>
#include <string>
#include <sstream>
#include <iomanip>
#include "model.hpp"
#include "view.hpp"

class AppController {
public:

	static std::pair<std::string, std::string> extractCredentials(const std::string& body) {
    // Example body: username=someuser&password=somepass
    size_t userPos = body.find("username=");
    size_t passPos = body.find("&password=");

    std::string username = "";
    std::string password = "";

    if (userPos != std::string::npos && passPos != std::string::npos) {
        username = body.substr(userPos + 9, passPos - (userPos + 9));
        password = body.substr(passPos + 10);
    }

    return {username, password};
	}

    static void setupRoutes(crow::SimpleApp& app, UserModel& model) {
        // Home/Login Page
        CROW_ROUTE(app, "/")([]() {
            return crow::response(loginForm());
        });
		
		CROW_ROUTE(app, "/s")([]() {
            return crow::response(signupForm());
        });
		

        // In the login POST route, update the success branch:
        // Update the "/w" route:
        CROW_ROUTE(app, "/w")([&model]() {
            auto user = model.getUser().value();
            return crow::response(welcomePage(user.username, user.role, model.getPortfolioInfo()));
        });
		
		CROW_ROUTE(app, "/logs")([&model]() {
            return crow::response(logsInfoForm(model.getLogs()));
        });

        // In the login POST route:
        CROW_ROUTE(app, "/login").methods(crow::HTTPMethod::POST)
        ([&model](const crow::request& req) {
            auto [username, password] = extractCredentials(req.body);
            int rt = model.login(username, password);
            if (rt == 0) {
                auto user = model.getUser().value();
                return crow::response(welcomePage(user.username, user.role, model.getPortfolioInfo()));
            } else if (rt == 1) {
                return crow::response(loginForm("Invalid username or password."));
            } else {
                return crow::response(loginForm("Please Logout First"));
            }
        });

        // In the signup POST route:
        CROW_ROUTE(app, "/signup").methods(crow::HTTPMethod::POST)
        ([&model](const crow::request& req) {
            auto [username, password] = extractCredentials(req.body);
            int rt = model.signup(username, password);
            if (rt == 0) {
                // Use three parameters here, e.g. using model.getPortfolioInfo() as portfolio info.
                return crow::response(welcomePage(username, "trader", model.getPortfolioInfo()));
            } else if (rt == 1) {
                return crow::response(signupForm("Username already taken"));
            } else {
                return crow::response(signupForm("Please Logout First"));
            }
        });
        CROW_ROUTE(app, "/stock_info")([&model]() {
            return crow::response(stockInfoForm(model.getStocks()));
        });
        // Logout Logic
        CROW_ROUTE(app, "/logout")
        ([&model](const crow::request& req) 
		{
            model.logout();
            return crow::response(logoutPage());
        });
		
		CROW_ROUTE(app, "/r")([]() {
            return crow::response(recommForm());
        });
		
		 CROW_ROUTE(app, "/recommend").methods(crow::HTTPMethod::POST)
        ([&model](const crow::request& req) {
			std::cout<<"Recommentation-->"<<req.body.substr(10)<<std::endl;
			return crow::response(recommForm(model.askLLM(req.body.substr(10))));
		});
		
		CROW_ROUTE(app, "/c")([&model]() {
            return crow::response(chatForm(model.chatRead()));
        });
		
		CROW_ROUTE(app, "/chat").methods(crow::HTTPMethod::POST)
        ([&model](const crow::request& req) {
            auto msg=req.body.substr(5);
			return crow::response(chatForm(model.chatUpdate(msg)));
        });

        CROW_ROUTE(app, "/buy").methods(crow::HTTPMethod::GET)
([](){
    return crow::response(buyForm());
});

// POST route to process the Buy order.
CROW_ROUTE(app, "/buy").methods(crow::HTTPMethod::POST)
([&model](const crow::request& req) {
    // Expected body format: "stockSymbol=XYZ&quantity=10"
    std::string body = req.body;
    size_t pos1 = body.find("stockSymbol=");
    size_t pos2 = body.find("&quantity=");
    if (pos1 == std::string::npos || pos2 == std::string::npos) {
        return crow::response(buyForm("Invalid input!"));
    }
    std::string stockSymbol = body.substr(pos1 + 12, pos2 - (pos1 + 12));
    std::string quantityStr = body.substr(pos2 + 10);
    int quantity = std::stoi(quantityStr);
    
    bool success = model.buyStock(stockSymbol, quantity);
    if (success)
        return crow::response(stockInfoForm("Purchase successful!"));
    else
        return crow::response(buyForm("Purchase failed!"));
});
// GET route to display the Sell Stock form.
CROW_ROUTE(app, "/sell").methods(crow::HTTPMethod::GET)
([](){
    return crow::response(sellForm());
});

// POST route to process the Sell order.
CROW_ROUTE(app, "/sell").methods(crow::HTTPMethod::POST)
([&model](const crow::request& req) {
    // Expected body format: "stockSymbol=XYZ&quantity=10"
    std::string body = req.body;
    size_t pos1 = body.find("stockSymbol=");
    size_t pos2 = body.find("&quantity=");
    if (pos1 == std::string::npos || pos2 == std::string::npos) {
        return crow::response(sellForm("Invalid input!"));
    }
    std::string stockSymbol = body.substr(pos1 + 12, pos2 - (pos1 + 12));
    std::string quantityStr = body.substr(pos2 + 10);
    int quantity = std::stoi(quantityStr);
    
    bool success = model.sellStock(stockSymbol, quantity);
    if (success)
        return crow::response(stockInfoForm("Sale successful!"));
    else
        return crow::response(sellForm("Sale failed!"));
});
		
    }
};
