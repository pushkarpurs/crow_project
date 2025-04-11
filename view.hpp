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


std::string welcomePage(const std::string& username, const std::string& role, const std::string& portfolioInfo) {
    return R"(
        <html>
        <head><title>Dashboard</title></head>
        <body>
            <h1>Hello, )" + role + " " + username + R"(</h1>
            <div>
                <h2>Your Portfolio</h2>
                )" + portfolioInfo + R"(
            </div>
            <div style="display: flex; gap: 10px;">
                <button onclick="window.location.href='/logout'" style="padding: 10px 20px; background-color: #007bff; color: white; border: none; border-radius: 5px;">Logout</button>
                <button onclick="window.location.href='/r'" style="padding: 10px 20px; background-color: #007bff; color: white; border: none; border-radius: 5px;">Recommendations</button>
                <button onclick="window.location.href='/c'" style="padding: 10px 20px; background-color: #007bff; color: white; border: none; border-radius: 5px;">Discussions</button>
                <button onclick="window.location.href='/stock_info'" style="padding: 10px 20px; background-color: #007bff; color: white; border: none; border-radius: 5px;">Stock Information</button>
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

std::string stockInfoForm(const std::string& stocks = "") {
    return R"(
        <html>
        <head><title>Stock Information</title></head>
        <body>
            <h2>Stock Information</h2>
            <div>
                )" + stocks + R"(
            </div>
            <button onclick="window.location.href='/w'" style="padding: 10px 20px; background-color: #28a745; color: white; border: none; border-radius: 5px; margin-top: 10px;">
                Dashboard
            </button>
                    <button onclick="window.location.href='/buy'" style="padding: 10px 20px; background-color: #28a745; color: white; border: none; border-radius: 5px; margin-top: 10px;">
                Buy
            </button>
            <button onclick="window.location.href='/sell'" style="padding: 10px 20px; background-color: #28a745; color: white; border: none; border-radius: 5px; margin-top: 10px;">
                Sell
            </button>
        </body>
        </html>
    )";
}

std::string buyForm(const std::string& message = "") {
    return std::string(R"DELIM(
<html>
<head><title>Buy Stock</title></head>
<body>
    <h2>Buy Stock</h2>
    <form method="POST" action="/buy">
        Stock Symbol: <input name="stockSymbol" type="text" /><br/>
        Quantity: <input name="quantity" type="number" /><br/>
        <input type="submit" value="Buy" />
    </form>
    <p style='color:red;'>)DELIM") + message + std::string(R"DELIM(
    </p>
    <button onclick="window.location.href='/w'" style="padding: 10px 20px; background-color: #28a745; color: white; border: none; border-radius: 5px; margin-top: 10px;">
        Dashboard
    </button>
</body>     
</html>
)DELIM");
} 

std::string sellForm(const std::string& message = "") {
    return std::string(R"DELIM(
<html>
<head><title>Sell Stock</title></head>
<body>
    <h2>Sell Stock</h2>
    <form method="POST" action="/sell">
        Stock Symbol: <input name="stockSymbol" type="text" /><br/>
        Quantity: <input name="quantity" type="number" /><br/>
        <input type="submit" value="Sell" />
    </form>
    <p style='color:red;'>)DELIM") + message + std::string(R"DELIM(
    </p>
    <button onclick="window.location.href='/w'" style="padding: 10px 20px; background-color: #28a745; color: white; border: none; border-radius: 5px; margin-top: 10px;">
        Dashboard
    </button>
</body>
</html>
)DELIM");
}