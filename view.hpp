// view.hpp
#pragma once
#include <string>

std::string loginForm(const std::string& message = "") {
    return R"(
        <html>
        <head><title>Login</title></head>
        <body>
            <h2>Login Page</h2>
            <form method="POST" action="/login">
                Username: <input name="username" /><br/>
                Password: <input name="password" type="password" /><br/>
                <input type="submit" value="Login" />
            </form>
			<button onclick="window.location.href='/s'" style="padding: 10px 20px; background-color: #28a745; color: white; border: none; border-radius: 5px; margin-top: 10px;">
                Signup
            </button>
            <p style='color:red;'>)" + message + R"(</p>
        </body>
        </html>
    )";
}

std::string signupForm(const std::string& message = "") {
    return R"(
        <html>
        <head><title>Signup</title></head>
        <body>
            <h2>Signup Page</h2>
            <form method="POST" action="/signup">
                Username: <input name="username" /><br/>
                Password: <input name="password" type="password" /><br/>
                <input type="submit" value="Signup" />
            </form>
            <button onclick="window.location.href='/'" style="padding: 10px 20px; background-color: #28a745; color: white; border: none; border-radius: 5px; margin-top: 10px;">
                Login
            </button>
            <p style='color:red;'>)" + message + R"(</p>
        </body>
        </html>
    )";
}


std::string welcomePage(const std::string& username, const std::string& role) {
    std::cout << username << " " << role << std::endl;

    return R"(
        <html>
		<head><title>Dashboard</title></head>
        <body>
            <h1>Hello, )" + role + " " + username + R"(</h1>
			<div style="display: flex; gap: 10px;">
            <button onclick="window.location.href='/logout'" style="padding: 10px 20px; background-color: #007bff; color: white; border: none; border-radius: 5px;">
                Logout
            </button>
			<button onclick="window.location.href='/r'" style="padding: 10px 20px; background-color: #007bff; color: white; border: none; border-radius: 5px;">
                Recommendations
            </button>
			<button onclick="window.location.href='/c'" style="padding: 10px 20px; background-color: #007bff; color: white; border: none; border-radius: 5px;">
                Discussions
            </button>
			</div>
        </body>
        </html>
    )";
}


std::string logoutPage() {
    return R"(
        <html>
		<head><title>Logout</title></head>
        <body>
            <h2>You have been logged out.</h2>
            <button onclick="window.location.href='/'" style="padding: 10px 20px; background-color: #007bff; color: white; border: none; border-radius: 5px;">
                Login again
            </button>
        </body>
        </html>
    )";
}
	
std::string recommForm(const std::string& message = "") {
    return R"(
        <html>
        <head><title>Recommend</title></head>
        <body>
            <h2>Get Stock Recommendations</h2>
            <form method="POST" action="/recommend">
                Stockname: <input name="stockname" /><br/>
                <input type="submit" value="Submit" />
            </form>
			<button onclick="window.location.href='/w'" style="padding: 10px 20px; background-color: #28a745; color: white; border: none; border-radius: 5px; margin-top: 10px;">
                Dashboard
            </button>
            <p style='color:red;'>)" + message + R"(</p>
        </body>
        </html>
    )";
}

std::string chatForm(const std::string& message = "") {
    return R"(
        <html>
        <head><title>Chat</title></head>
        <body>
            <h2>Local Chat</h2>
			<p style='color:red;'>)" + message + R"(</p>
            <form method="POST" action="/chat">
                Chat: <input name="chat" /><br/>
                <input type="submit" value="Send" />
            </form>
			<button onclick="window.location.href='/w'" style="padding: 10px 20px; background-color: #28a745; color: white; border: none; border-radius: 5px; margin-top: 10px;">
                Dashboard
            </button>
        </body>
        </html>
    )";
}
