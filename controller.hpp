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
		
		CROW_ROUTE(app, "/w")([&model]() {
            auto user = model.getUser().value();
			return crow::response(welcomePage(user.username, user.role));
        });
		
        // Login Logic
        CROW_ROUTE(app, "/login").methods(crow::HTTPMethod::POST)
        ([&model](const crow::request& req) {
            auto [username, password] = extractCredentials(req.body);
			
			std::cout<<"Logging In"<<username <<"111"<<password<<std::endl;
			
			int rt=model.login(username, password);
			
            if (rt==0) {
                auto user = model.getUser().value();
				std::cout<<"Logging In"<<user.role<<std::endl;
                return crow::response(welcomePage(user.username, user.role));
            } else if(rt==1) {
                return crow::response(loginForm("Invalid username or password."));
            }
			else{
				return crow::response(loginForm("Please Logout First"));
			}
        });
		
		CROW_ROUTE(app, "/signup").methods(crow::HTTPMethod::POST)
        ([&model](const crow::request& req) {
            auto [username, password] = extractCredentials(req.body);
			
			std::cout<<"Signing up In"<<username <<"111"<<password<<std::endl;
			
			int rt=model.signup(username, password);
			
            if (rt==0) {
                return crow::response(welcomePage(username, "trader"));
            } else if(rt==1) {
                return crow::response(signupForm("Username already taken"));
            }
			else{
				return crow::response(signupForm("Please Logout First"));
			}
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
		
    }
};
