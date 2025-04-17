#pragma once
#include <string>

std::string loginForm(const std::string& message = "") {
    return R"(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login | StockTrader</title>
    <style>
        :root {
            --primary: #4f46e5;
            --primary-hover: #4338ca;
            --secondary: #10b981;
            --secondary-hover: #059669;
            --danger: #ef4444;
            --background: #f9fafb;
            --card: #ffffff;
            --text: #1f2937;
            --text-secondary: #6b7280;
            --border: #e5e7eb;
        }
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;
        }
        body {
            background-color: var(--background);
            color: var(--text);
            display: flex;
            justify-content: center;
            align-items: center;
            min-height: 100vh;
            padding: 1rem;
        }
        .card {
            background-color: var(--card);
            border-radius: 0.5rem;
            box-shadow: 0 4px 6px -1px rgba(0, 0, 0, 0.1), 0 2px 4px -1px rgba(0, 0, 0, 0.06);
            width: 100%;
            max-width: 400px;
            padding: 2rem;
        }
        .logo {
            font-size: 1.5rem;
            font-weight: 700;
            color: var(--primary);
            margin-bottom: 1.5rem;
            text-align: center;
        }
        h2 {
            font-size: 1.5rem;
            font-weight: 600;
            margin-bottom: 1.5rem;
            text-align: center;
        }
        .form-group {
            margin-bottom: 1rem;
        }
        label {
            display: block;
            margin-bottom: 0.5rem;
            font-weight: 500;
        }
        input {
            width: 100%;
            padding: 0.75rem;
            border: 1px solid var(--border);
            border-radius: 0.375rem;
            font-size: 1rem;
            transition: border-color 0.15s ease-in-out;
        }
        input:focus {
            outline: none;
            border-color: var(--primary);
            box-shadow: 0 0 0 3px rgba(79, 70, 229, 0.1);
        }
        .btn {
            display: inline-block;
            padding: 0.75rem 1rem;
            font-size: 1rem;
            font-weight: 500;
            text-align: center;
            text-decoration: none;
            border-radius: 0.375rem;
            border: none;
            cursor: pointer;
            transition: background-color 0.15s ease-in-out;
            width: 100%;
        }
        .btn-primary {
            background-color: var(--primary);
            color: white;
        }
        .btn-primary:hover {
            background-color: var(--primary-hover);
        }
        .btn-secondary {
            background-color: var(--secondary);
            color: white;
            margin-top: 0.75rem;
        }
        .btn-secondary:hover {
            background-color: var(--secondary-hover);
        }
        .error-message {
            color: var(--danger);
            margin-top: 1rem;
            text-align: center;
        }
        .footer {
            margin-top: 1.5rem;
            text-align: center;
            font-size: 0.875rem;
            color: var(--text-secondary);
        }
    </style>
</head>
<body>
    <div class="card">
        <div class="logo">StockTrader</div>
        <h2>Login</h2>
        <form method="POST" action="/login">
            <div class="form-group">
                <label for="username">Username</label>
                <input id="username" name="username" type="text" required autocomplete="username" />
            </div>
            <div class="form-group">
                <label for="password">Password</label>
                <input id="password" name="password" type="password" required autocomplete="current-password" />
            </div>
            <button type="submit" class="btn btn-primary">Login</button>
        </form>
        <button onclick="window.location.href='/s'" class="btn btn-secondary">Create Account</button>
        <div class="error-message">)" + message + R"(</div>
        <div class="footer">
            &copy; 2025 StockTrader. All rights reserved.
        </div>
    </div>
</body>
</html>
    )";
}

std::string signupForm(const std::string& message = "") {
    return R"(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Sign Up | StockTrader</title>
    <style>
        :root {
            --primary: #4f46e5;
            --primary-hover: #4338ca;
            --secondary: #10b981;
            --secondary-hover: #059669;
            --danger: #ef4444;
            --background: #f9fafb;
            --card: #ffffff;
            --text: #1f2937;
            --text-secondary: #6b7280;
            --border: #e5e7eb;
        }
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;
        }
        body {
            background-color: var(--background);
            color: var(--text);
            display: flex;
            justify-content: center;
            align-items: center;
            min-height: 100vh;
            padding: 1rem;
        }
        .card {
            background-color: var(--card);
            border-radius: 0.5rem;
            box-shadow: 0 4px 6px -1px rgba(0, 0, 0, 0.1), 0 2px 4px -1px rgba(0, 0, 0, 0.06);
            width: 100%;
            max-width: 400px;
            padding: 2rem;
        }
        .logo {
            font-size: 1.5rem;
            font-weight: 700;
            color: var(--primary);
            margin-bottom: 1.5rem;
            text-align: center;
        }
        h2 {
            font-size: 1.5rem;
            font-weight: 600;
            margin-bottom: 1.5rem;
            text-align: center;
        }
        .form-group {
            margin-bottom: 1rem;
        }
        label {
            display: block;
            margin-bottom: 0.5rem;
            font-weight: 500;
        }
        input {
            width: 100%;
            padding: 0.75rem;
            border: 1px solid var(--border);
            border-radius: 0.375rem;
            font-size: 1rem;
            transition: border-color 0.15s ease-in-out;
        }
        input:focus {
            outline: none;
            border-color: var(--primary);
            box-shadow: 0 0 0 3px rgba(79, 70, 229, 0.1);
        }
        .btn {
            display: inline-block;
            padding: 0.75rem 1rem;
            font-size: 1rem;
            font-weight: 500;
            text-align: center;
            text-decoration: none;
            border-radius: 0.375rem;
            border: none;
            cursor: pointer;
            transition: background-color 0.15s ease-in-out;
            width: 100%;
        }
        .btn-primary {
            background-color: var(--primary);
            color: white;
        }
        .btn-primary:hover {
            background-color: var(--primary-hover);
        }
        .btn-secondary {
            background-color: var(--secondary);
            color: white;
            margin-top: 0.75rem;
        }
        .btn-secondary:hover {
            background-color: var(--secondary-hover);
        }
        .error-message {
            color: var(--danger);
            margin-top: 1rem;
            text-align: center;
        }
        .footer {
            margin-top: 1.5rem;
            text-align: center;
            font-size: 0.875rem;
            color: var(--text-secondary);
        }
    </style>
</head>
<body>
    <div class="card">
        <div class="logo">StockTrader</div>
        <h2>Create Account</h2>
        <form method="POST" action="/signup">
            <div class="form-group">
                <label for="username">Username</label>
                <input id="username" name="username" type="text" required autocomplete="username" />
            </div>
            <div class="form-group">
                <label for="password">Password</label>
                <input id="password" name="password" type="password" required autocomplete="new-password" />
            </div>
            <button type="submit" class="btn btn-primary">Sign Up</button>
        </form>
        <button onclick="window.location.href='/'" class="btn btn-secondary">Back to Login</button>
        <div class="error-message">)" + message + R"(</div>
        <div class="footer">
            &copy; 2025 StockTrader. All rights reserved.
        </div>
    </div>
</body>
</html>
    )";
}

std::string welcomePage(const std::string& username, const std::string& role, const std::string& portfolioInfo) {
    return R"(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Dashboard | StockTrader</title>
    <style>
        :root {
            --primary: #4f46e5;
            --primary-hover: #4338ca;
            --secondary: #10b981;
            --secondary-hover: #059669;
            --danger: #ef4444;
            --background: #f9fafb;
            --card: #ffffff;
            --text: #1f2937;
            --text-secondary: #6b7280;
            --border: #e5e7eb;
        }
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;
        }
        body {
            background-color: var(--background);
            color: var(--text);
            min-height: 100vh;
        }
        .container {
            max-width: 1200px;
            margin: 0 auto;
            padding: 1rem;
        }
        .header {
            display: flex;
            justify-content: space-between;
            align-items: center;
            padding: 1rem 0;
            border-bottom: 1px solid var(--border);
            margin-bottom: 2rem;
        }
        .logo {
            font-size: 1.5rem;
            font-weight: 700;
            color: var(--primary);
        }
        .user-info {
            display: flex;
            align-items: center;
            gap: 0.5rem;
        }
        .user-role {
            background-color: var(--primary);
            color: white;
            padding: 0.25rem 0.5rem;
            border-radius: 0.25rem;
            font-size: 0.75rem;
            font-weight: 500;
        }
        .user-name {
            font-weight: 500;
        }
        .card {
            background-color: var(--card);
            border-radius: 0.5rem;
            box-shadow: 0 1px 3px 0 rgba(0, 0, 0, 0.1), 0 1px 2px 0 rgba(0, 0, 0, 0.06);
            padding: 1.5rem;
            margin-bottom: 1.5rem;
        }
        h1 {
            font-size: 1.5rem;
            font-weight: 600;
            margin-bottom: 1rem;
        }
        h2 {
            font-size: 1.25rem;
            font-weight: 600;
            margin-bottom: 1rem;
            color: var(--primary);
        }
        .portfolio-info {
            margin-bottom: 1.5rem;
        }
        .actions {
            display: flex;
            flex-wrap: wrap;
            gap: 0.75rem;
            margin-top: 1.5rem;
        }
        .btn {
            display: inline-block;
            padding: 0.75rem 1rem;
            font-size: 0.875rem;
            font-weight: 500;
            text-align: center;
            text-decoration: none;
            border-radius: 0.375rem;
            border: none;
            cursor: pointer;
            transition: background-color 0.15s ease-in-out;
        }
        .btn-primary {
            background-color: var(--primary);
            color: white;
        }
        .btn-primary:hover {
            background-color: var(--primary-hover);
        }
        .btn-secondary {
            background-color: var(--secondary);
            color: white;
        }
        .btn-secondary:hover {
            background-color: var(--secondary-hover);
        }
        .btn-danger {
            background-color: var(--danger);
            color: white;
        }
        .footer {
            text-align: center;
            padding: 1.5rem 0;
            margin-top: 2rem;
            border-top: 1px solid var(--border);
            color: var(--text-secondary);
            font-size: 0.875rem;
        }
        @media (max-width: 640px) {
            .actions {
                flex-direction: column;
            }
            .btn {
                width: 100%;
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <header class="header">
            <div class="logo">StockTrader</div>
            <div class="user-info">
                <span class="user-role">)" + role + R"(</span>
                <span class="user-name">)" + username + R"(</span>
            </div>
        </header>
        
        <main>
            <div class="card">
                <h1>Welcome to your Dashboard</h1>
                <div class="portfolio-info">
                    <h2>Your Portfolio</h2>
                    <div>)" + portfolioInfo + R"(</div>
                </div>
                
                <div class="actions">
                    <button onclick="window.location.href='/stock_info'" class="btn btn-primary">Stock Information</button>
                    <button onclick="window.location.href='/r'" class="btn btn-primary">Recommendations</button>
                    <button onclick="window.location.href='/c'" class="btn btn-primary">Discussions</button>
					<button onclick="window.location.href='/logs'" class="btn btn-primary">See Logs</button>
                    <button onclick="window.location.href='/logout'" class="btn btn-danger">Logout</button>
                </div>
            </div>
        </main>
        
        <footer class="footer">
            &copy; 2025 StockTrader. All rights reserved.
        </footer>
    </div>
</body>
</html>
    )";
}

std::string logoutPage() {
    return R"(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Logged Out | StockTrader</title>
    <style>
        :root {
            --primary: #4f46e5;
            --primary-hover: #4338ca;
            --background: #f9fafb;
            --card: #ffffff;
            --text: #1f2937;
            --text-secondary: #6b7280;
            --border: #e5e7eb;
        }
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;
        }
        body {
            background-color: var(--background);
            color: var(--text);
            display: flex;
            justify-content: center;
            align-items: center;
            min-height: 100vh;
            padding: 1rem;
        }
        .card {
            background-color: var(--card);
            border-radius: 0.5rem;
            box-shadow: 0 4px 6px -1px rgba(0, 0, 0, 0.1), 0 2px 4px -1px rgba(0, 0, 0, 0.06);
            width: 100%;
            max-width: 400px;
            padding: 2rem;
            text-align: center;
        }
        .logo {
            font-size: 1.5rem;
            font-weight: 700;
            color: var(--primary);
            margin-bottom: 1.5rem;
        }
        h2 {
            font-size: 1.25rem;
            font-weight: 600;
            margin-bottom: 1.5rem;
        }
        .btn {
            display: inline-block;
            padding: 0.75rem 1rem;
            font-size: 1rem;
            font-weight: 500;
            text-align: center;
            text-decoration: none;
            border-radius: 0.375rem;
            border: none;
            cursor: pointer;
            transition: background-color 0.15s ease-in-out;
        }
        .btn-primary {
            background-color: var(--primary);
            color: white;
        }
        .btn-primary:hover {
            background-color: var(--primary-hover);
        }
        .footer {
            margin-top: 1.5rem;
            color: var(--text-secondary);
            font-size: 0.875rem;
        }
    </style>
</head>
<body>
    <div class="card">
        <div class="logo">StockTrader</div>
        <h2>You have been logged out successfully</h2>
        <button onclick="window.location.href='/'" class="btn btn-primary">Login again</button>
        <div class="footer">
            &copy; 2025 StockTrader. All rights reserved.
        </div>
    </div>
</body>
</html>
    )";
}

std::string recommForm(const std::string& message = "") {
    return R"(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Stock Recommendations | StockTrader</title>
    <style>
        :root {
            --primary: #4f46e5;
            --primary-hover: #4338ca;
            --secondary: #10b981;
            --secondary-hover: #059669;
            --danger: #ef4444;
            --background: #f9fafb;
            --card: #ffffff;
            --text: #1f2937;
            --text-secondary: #6b7280;
            --border: #e5e7eb;
        }
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;
        }
        body {
            background-color: var(--background);
            color: var(--text);
            min-height: 100vh;
        }
        .container {
            max-width: 800px;
            margin: 0 auto;
            padding: 1rem;
        }
        .header {
            display: flex;
            justify-content: space-between;
            align-items: center;
            padding: 1rem 0;
            border-bottom: 1px solid var(--border);
            margin-bottom: 2rem;
        }
        .logo {
            font-size: 1.5rem;
            font-weight: 700;
            color: var(--primary);
        }
        .card {
            background-color: var(--card);
            border-radius: 0.5rem;
            box-shadow: 0 1px 3px 0 rgba(0, 0, 0, 0.1), 0 1px 2px 0 rgba(0, 0, 0, 0.06);
            padding: 1.5rem;
            margin-bottom: 1.5rem;
        }
        h2 {
            font-size: 1.25rem;
            font-weight: 600;
            margin-bottom: 1.5rem;
            color: var(--primary);
        }
        .form-group {
            margin-bottom: 1rem;
        }
        label {
            display: block;
            margin-bottom: 0.5rem;
            font-weight: 500;
        }
        input {
            width: 100%;
            padding: 0.75rem;
            border: 1px solid var(--border);
            border-radius: 0.375rem;
            font-size: 1rem;
            transition: border-color 0.15s ease-in-out;
        }
        input:focus {
            outline: none;
            border-color: var(--primary);
            box-shadow: 0 0 0 3px rgba(79, 70, 229, 0.1);
        }
        .btn {
            display: inline-block;
            padding: 0.75rem 1rem;
            font-size: 0.875rem;
            font-weight: 500;
            text-align: center;
            text-decoration: none;
            border-radius: 0.375rem;
            border: none;
            cursor: pointer;
            transition: background-color 0.15s ease-in-out;
        }
        .btn-primary {
            background-color: var(--primary);
            color: white;
        }
        .btn-primary:hover {
            background-color: var(--primary-hover);
        }
        .btn-secondary {
            background-color: var(--secondary);
            color: white;
            margin-left: 0.5rem;
        }
        .btn-secondary:hover {
            background-color: var(--secondary-hover);
        }
        .error-message {
            color: var(--danger);
            margin-top: 1rem;
        }
        .actions {
            display: flex;
            margin-top: 1.5rem;
        }
        .footer {
            text-align: center;
            padding: 1.5rem 0;
            margin-top: 2rem;
            border-top: 1px solid var(--border);
            color: var(--text-secondary);
            font-size: 0.875rem;
        }
        @media (max-width: 640px) {
            .actions {
                flex-direction: column;
                gap: 0.5rem;
            }
            .btn {
                width: 100%;
                margin-left: 0;
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <header class="header">
            <div class="logo">StockTrader</div>
        </header>
        
        <main>
            <div class="card">
                <h2>Get Stock Recommendations</h2>
                <form method="POST" action="/recommend">
                    <div class="form-group">
                        <label for="stockname">Stock Symbol</label>
                        <input id="stockname" name="stockname" type="text" required placeholder="e.g. AAPL, MSFT, GOOGL" />
                    </div>
                    <div class="actions">
                        <button type="submit" class="btn btn-primary">Get Recommendations</button>
                        <button type="button" onclick="window.location.href='/w'" class="btn btn-secondary">Back to Dashboard</button>
                    </div>
                </form>
                <div class="error-message">)" + message + R"(</div>
            </div>
        </main>
        
        <footer class="footer">
            &copy; 2025 StockTrader. All rights reserved.
        </footer>
    </div>
</body>
</html>
    )";
}

std::string chatForm(const std::string& message = "") {
    return R"(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Discussions | StockTrader</title>
    <style>
        :root {
            --primary: #4f46e5;
            --primary-hover: #4338ca;
            --secondary: #10b981;
            --secondary-hover: #059669;
            --danger: #ef4444;
            --background: #f9fafb;
            --card: #ffffff;
            --text: #1f2937;
            --text-secondary: #6b7280;
            --border: #e5e7eb;
        }
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;
        }
        body {
            background-color: var(--background);
            color: var(--text);
            min-height: 100vh;
        }
        .container {
            max-width: 800px;
            margin: 0 auto;
            padding: 1rem;
        }
        .header {
            display: flex;
            justify-content: space-between;
            align-items: center;
            padding: 1rem 0;
            border-bottom: 1px solid var(--border);
            margin-bottom: 2rem;
        }
        .logo {
            font-size: 1.5rem;
            font-weight: 700;
            color: var(--primary);
        }
        .card {
            background-color: var(--card);
            border-radius: 0.5rem;
            box-shadow: 0 1px 3px 0 rgba(0, 0, 0, 0.1), 0 1px 2px 0 rgba(0, 0, 0, 0.06);
            padding: 1.5rem;
            margin-bottom: 1.5rem;
        }
        h2 {
            font-size: 1.25rem;
            font-weight: 600;
            margin-bottom: 1.5rem;
            color: var(--primary);
        }
        .chat-form {
            display: flex;
            gap: 0.5rem;
        }
        input {
            flex: 1;
            padding: 0.75rem;
            border: 1px solid var(--border);
            border-radius: 0.375rem;
            font-size: 1rem;
            transition: border-color 0.15s ease-in-out;
        }
        input:focus {
            outline: none;
            border-color: var(--primary);
            box-shadow: 0 0 0 3px rgba(79, 70, 229, 0.1);
        }
        .btn {
            display: inline-block;
            padding: 0.75rem 1rem;
            font-size: 0.875rem;
            font-weight: 500;
            text-align: center;
            text-decoration: none;
            border-radius: 0.375rem;
            border: none;
            cursor: pointer;
            transition: background-color 0.15s ease-in-out;
        }
        .btn-primary {
            background-color: var(--primary);
            color: white;
        }
        .btn-primary:hover {
            background-color: var(--primary-hover);
        }
        .btn-secondary {
            background-color: var(--secondary);
            color: white;
        }
        .btn-secondary:hover {
            background-color: var(--secondary-hover);
        }
        .error-message {
            color: var(--danger);
            margin-bottom: 1rem;
        }
        .back-button {
            margin-top: 1.5rem;
            text-align: center;
        }
        .footer {
            text-align: center;
            padding: 1.5rem 0;
            margin-top: 2rem;
            border-top: 1px solid var(--border);
            color: var(--text-secondary);
            font-size: 0.875rem;
        }
        @media (max-width: 640px) {
            .chat-form {
                flex-direction: column;
            }
            .btn {
                width: 100%;
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <header class="header">
            <div class="logo">StockTrader</div>
        </header>
        
        <main>
            <div class="card">
                <h2>Community Discussions</h2>
                <div class="error-message">)" + message + R"(</div>
                <form method="POST" action="/chat" class="chat-form">
                    <input name="chat" type="text" placeholder="Share your thoughts or ask a question..." required />
                    <button type="submit" class="btn btn-primary">Send</button>
                </form>
                <div class="back-button">
                    <button onclick="window.location.href='/w'" class="btn btn-secondary">Back to Dashboard</button>
                </div>
            </div>
        </main>
        
        <footer class="footer">
            &copy; 2025 StockTrader. All rights reserved.
        </footer>
    </div>
</body>
</html>
    )";
}

std::string stockInfoForm(const std::string& stocks = "") {
    return R"(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Stock Information | StockTrader</title>
    <style>
        :root {
            --primary: #4f46e5;
            --primary-hover: #4338ca;
            --secondary: #10b981;
            --secondary-hover: #059669;
            --danger: #ef4444;
            --background: #f9fafb;
            --card: #ffffff;
            --text: #1f2937;
            --text-secondary: #6b7280;
            --border: #e5e7eb;
        }
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;
        }
        body {
            background-color: var(--background);
            color: var(--text);
            min-height: 100vh;
        }
        .container {
            max-width: 1000px;
            margin: 0 auto;
            padding: 1rem;
        }
        .header {
            display: flex;
            justify-content: space-between;
            align-items: center;
            padding: 1rem 0;
            border-bottom: 1px solid var(--border);
            margin-bottom: 2rem;
        }
        .logo {
            font-size: 1.5rem;
            font-weight: 700;
            color: var(--primary);
        }
        .card {
            background-color: var(--card);
            border-radius: 0.5rem;
            box-shadow: 0 1px 3px 0 rgba(0, 0, 0, 0.1), 0 1px 2px 0 rgba(0, 0, 0, 0.06);
            padding: 1.5rem;
            margin-bottom: 1.5rem;
        }
        h2 {
            font-size: 1.25rem;
            font-weight: 600;
            margin-bottom: 1.5rem;
            color: var(--primary);
        }
        .stocks-container {
            margin-bottom: 1.5rem;
        }
        .actions {
            display: flex;
            flex-wrap: wrap;
            gap: 0.75rem;
            margin-top: 1.5rem;
        }
        .btn {
            display: inline-block;
            padding: 0.75rem 1rem;
            font-size: 0.875rem;
            font-weight: 500;
            text-align: center;
            text-decoration: none;
            border-radius: 0.375rem;
            border: none;
            cursor: pointer;
            transition: background-color 0.15s ease-in-out;
        }
        .btn-primary {
            background-color: var(--primary);
            color: white;
        }
        .btn-primary:hover {
            background-color: var(--primary-hover);
        }
        .btn-secondary {
            background-color: var(--secondary);
            color: white;
        }
        .btn-secondary:hover {
            background-color: var(--secondary-hover);
        }
        .footer {
            text-align: center;
            padding: 1.5rem 0;
            margin-top: 2rem;
            border-top: 1px solid var(--border);
            color: var(--text-secondary);
            font-size: 0.875rem;
        }
        @media (max-width: 640px) {
            .actions {
                flex-direction: column;
            }
            .btn {
                width: 100%;
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <header class="header">
            <div class="logo">StockTrader</div>
        </header>
        
        <main>
            <div class="card">
                <h2>Stock Information</h2>
                <div class="stocks-container">
                    )" + stocks + R"(
                </div>
                
                <div class="actions">
                    <button onclick="window.location.href='/buy'" class="btn btn-secondary">Buy Stocks</button>
                    <button onclick="window.location.href='/sell'" class="btn btn-secondary">Sell Stocks</button>
                    <button onclick="window.location.href='/w'" class="btn btn-primary">Back to Dashboard</button>
                </div>
            </div>
        </main>
        
        <footer class="footer">
            &copy; 2025 StockTrader. All rights reserved.
        </footer>
    </div>
</body>
</html>
    )";
}

std::string logsInfoForm(const std::string& stocks = "") {
    return R"(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Stock Information | StockTrader</title>
    <style>
        :root {
            --primary: #4f46e5;
            --primary-hover: #4338ca;
            --secondary: #10b981;
            --secondary-hover: #059669;
            --danger: #ef4444;
            --background: #f9fafb;
            --card: #ffffff;
            --text: #1f2937;
            --text-secondary: #6b7280;
            --border: #e5e7eb;
        }
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;
        }
        body {
            background-color: var(--background);
            color: var(--text);
            min-height: 100vh;
        }
        .container {
            max-width: 1000px;
            margin: 0 auto;
            padding: 1rem;
        }
        .header {
            display: flex;
            justify-content: space-between;
            align-items: center;
            padding: 1rem 0;
            border-bottom: 1px solid var(--border);
            margin-bottom: 2rem;
        }
        .logo {
            font-size: 1.5rem;
            font-weight: 700;
            color: var(--primary);
        }
        .card {
            background-color: var(--card);
            border-radius: 0.5rem;
            box-shadow: 0 1px 3px 0 rgba(0, 0, 0, 0.1), 0 1px 2px 0 rgba(0, 0, 0, 0.06);
            padding: 1.5rem;
            margin-bottom: 1.5rem;
        }
        h2 {
            font-size: 1.25rem;
            font-weight: 600;
            margin-bottom: 1.5rem;
            color: var(--primary);
        }
        .stocks-container {
            margin-bottom: 1.5rem;
        }
        .actions {
            display: flex;
            flex-wrap: wrap;
            gap: 0.75rem;
            margin-top: 1.5rem;
        }
        .btn {
            display: inline-block;
            padding: 0.75rem 1rem;
            font-size: 0.875rem;
            font-weight: 500;
            text-align: center;
            text-decoration: none;
            border-radius: 0.375rem;
            border: none;
            cursor: pointer;
            transition: background-color 0.15s ease-in-out;
        }
        .btn-primary {
            background-color: var(--primary);
            color: white;
        }
        .btn-primary:hover {
            background-color: var(--primary-hover);
        }
        .btn-secondary {
            background-color: var(--secondary);
            color: white;
        }
        .btn-secondary:hover {
            background-color: var(--secondary-hover);
        }
        .footer {
            text-align: center;
            padding: 1.5rem 0;
            margin-top: 2rem;
            border-top: 1px solid var(--border);
            color: var(--text-secondary);
            font-size: 0.875rem;
        }
        @media (max-width: 640px) {
            .actions {
                flex-direction: column;
            }
            .btn {
                width: 100%;
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <header class="header">
            <div class="logo">StockTrader</div>
        </header>
        
        <main>
            <div class="card">
                <h2>Stock Information</h2>
                <div class="stocks-container">
                    )" + stocks + R"(
                </div>
                
                <div class="actions">
                    <button onclick="window.location.href='/w'" class="btn btn-primary">Back to Dashboard</button>
                </div>
            </div>
        </main>
        
        <footer class="footer">
            &copy; 2025 StockTrader. All rights reserved.
        </footer>
    </div>
</body>
</html>
    )";
}



std::string buyForm(const std::string& message = "") {
    return R"(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Buy Stocks | StockTrader</title>
    <style>
        :root {
            --primary: #4f46e5;
            --primary-hover: #4338ca;
            --secondary: #10b981;
            --secondary-hover: #059669;
            --danger: #ef4444;
            --background: #f9fafb;
            --card: #ffffff;
            --text: #1f2937;
            --text-secondary: #6b7280;
            --border: #e5e7eb;
        }
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;
        }
        body {
            background-color: var(--background);
            color: var(--text);
            min-height: 100vh;
        }
        .container {
            max-width: 800px;
            margin: 0 auto;
            padding: 1rem;
        }
        .header {
            display: flex;
            justify-content: space-between;
            align-items: center;
            padding: 1rem 0;
            border-bottom: 1px solid var(--border);
            margin-bottom: 2rem;
        }
        .logo {
            font-size: 1.5rem;
            font-weight: 700;
            color: var(--primary);
        }
        .card {
            background-color: var(--card);
            border-radius: 0.5rem;
            box-shadow: 0 1px 3px 0 rgba(0, 0, 0, 0.1), 0 1px 2px 0 rgba(0, 0, 0, 0.06);
            padding: 1.5rem;
            margin-bottom: 1.5rem;
        }
        h2 {
            font-size: 1.25rem;
            font-weight: 600;
            margin-bottom: 1.5rem;
            color: var(--primary);
        }
        .form-group {
            margin-bottom: 1rem;
        }
        label {
            display: block;
            margin-bottom: 0.5rem;
            font-weight: 500;
        }
        input {
            width: 100%;
            padding: 0.75rem;
            border: 1px solid var(--border);
            border-radius: 0.375rem;
            font-size: 1rem;
            transition: border-color 0.15s ease-in-out;
        }
        input:focus {
            outline: none;
            border-color: var(--primary);
            box-shadow: 0 0 0 3px rgba(79, 70, 229, 0.1);
        }
        .btn {
            display: inline-block;
            padding: 0.75rem 1rem;
            font-size: 0.875rem;
            font-weight: 500;
            text-align: center;
            text-decoration: none;
            border-radius: 0.375rem;
            border: none;
            cursor: pointer;
            transition: background-color 0.15s ease-in-out;
        }
        .btn-primary {
            background-color: var(--primary);
            color: white;
        }
        .btn-primary:hover {
            background-color: var(--primary-hover);
        }
        .btn-secondary {
            background-color: var(--secondary);
            color: white;
            margin-left: 0.5rem;
        }
        .btn-secondary:hover {
            background-color: var(--secondary-hover);
        }
        .error-message {
            color: var(--danger);
            margin-top: 1rem;
        }
        .actions {
            display: flex;
            margin-top: 1.5rem;
        }
        .footer {
            text-align: center;
            padding: 1.5rem 0;
            margin-top: 2rem;
            border-top: 1px solid var(--border);
            color: var(--text-secondary);
            font-size: 0.875rem;
        }
        @media (max-width: 640px) {
            .actions {
                flex-direction: column;
                gap: 0.5rem;
            }
            .btn {
                width: 100%;
                margin-left: 0;
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <header class="header">
            <div class="logo">StockTrader</div>
        </header>
        
        <main>
            <div class="card">
                <h2>Buy Stocks</h2>
                <form method="POST" action="/buy">
                    <div class="form-group">
                        <label for="stockSymbol">Stock Symbol</label>
                        <input id="stockSymbol" name="stockSymbol" type="text" required placeholder="e.g. AAPL, MSFT, GOOGL" />
                    </div>
                    <div class="form-group">
                        <label for="quantity">Quantity</label>
                        <input id="quantity" name="quantity" type="number" min="1" required placeholder="Number of shares" />
                    </div>
                    <div class="actions">
                        <button type="submit" class="btn btn-primary">Buy Shares</button>
                        <button type="button" onclick="window.location.href='/w'" class="btn btn-secondary">Back to Dashboard</button>
                    </div>
                </form>
                <div class="error-message">)" + message + R"(</div>
            </div>
        </main>
        
        <footer class="footer">
            &copy; 2025 StockTrader. All rights reserved.
        </footer>
    </div>
</body>
</html>
    )";
}

std::string sellForm(const std::string& message = "") {
    return R"(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Sell Stocks | StockTrader</title>
    <style>
        :root {
            --primary: #4f46e5;
            --primary-hover: #4338ca;
            --secondary: #10b981;
            --secondary-hover: #059669;
            --danger: #ef4444;
            --background: #f9fafb;
            --card: #ffffff;
            --text: #1f2937;
            --text-secondary: #6b7280;
            --border: #e5e7eb;
        }
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;
        }
        body {
            background-color: var(--background);
            color: var(--text);
            min-height: 100vh;
        }
        .container {
            max-width: 800px;
            margin: 0 auto;
            padding: 1rem;
        }
        .header {
            display: flex;
            justify-content: space-between;
            align-items: center;
            padding: 1rem 0;
            border-bottom: 1px solid var(--border);
            margin-bottom: 2rem;
        }
        .logo {
            font-size: 1.5rem;
            font-weight: 700;
            color: var(--primary);
        }
        .card {
            background-color: var(--card);
            border-radius: 0.5rem;
            box-shadow: 0 1px 3px 0 rgba(0, 0, 0, 0.1), 0 1px 2px 0 rgba(0, 0, 0, 0.06);
            padding: 1.5rem;
            margin-bottom: 1.5rem;
        }
        h2 {
            font-size: 1.25rem;
            font-weight: 600;
            margin-bottom: 1.5rem;
            color: var(--primary);
        }
        .form-group {
            margin-bottom: 1rem;
        }
        label {
            display: block;
            margin-bottom: 0.5rem;
            font-weight: 500;
        }
        input {
            width: 100%;
            padding: 0.75rem;
            border: 1px solid var(--border);
            border-radius: 0.375rem;
            font-size: 1rem;
            transition: border-color 0.15s ease-in-out;
        }
        input:focus {
            outline: none;
            border-color: var(--primary);
            box-shadow: 0 0 0 3px rgba(79, 70, 229, 0.1);
        }
        .btn {
            display: inline-block;
            padding: 0.75rem 1rem;
            font-size: 0.875rem;
            font-weight: 500;
            text-align: center;
            text-decoration: none;
            border-radius: 0.375rem;
            border: none;
            cursor: pointer;
            transition: background-color 0.15s ease-in-out;
        }
        .btn-primary {
            background-color: var(--primary);
            color: white;
        }
        .btn-primary:hover {
            background-color: var(--primary-hover);
        }
        .btn-secondary {
            background-color: var(--secondary);
            color: white;
            margin-left: 0.5rem;
        }
        .btn-secondary:hover {
            background-color: var(--secondary-hover);
        }
        .error-message {
            color: var(--danger);
            margin-top: 1rem;
        }
        .actions {
            display: flex;
            margin-top: 1.5rem;
        }
        .footer {
            text-align: center;
            padding: 1.5rem 0;
            margin-top: 2rem;
            border-top: 1px solid var(--border);
            color: var(--text-secondary);
            font-size: 0.875rem;
        }
        @media (max-width: 640px) {
            .actions {
                flex-direction: column;
                gap: 0.5rem;
            }
            .btn {
                width: 100%;
                margin-left: 0;
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <header class="header">
            <div class="logo">StockTrader</div>
        </header>
        
        <main>
            <div class="card">
                <h2>Sell Stocks</h2>
                <form method="POST" action="/sell">
                    <div class="form-group">
                        <label for="stockSymbol">Stock Symbol</label>
                        <input id="stockSymbol" name="stockSymbol" type="text" required placeholder="e.g. AAPL, MSFT, GOOGL" />
                    </div>
                    <div class="form-group">
                        <label for="quantity">Quantity</label>
                        <input id="quantity" name="quantity" type="number" min="1" required placeholder="Number of shares" />
                    </div>
                    <div class="actions">
                        <button type="submit" class="btn btn-primary">Sell Shares</button>
                        <button type="button" onclick="window.location.href='/w'" class="btn btn-secondary">Back to Dashboard</button>
                    </div>
                </form>
                <div class="error-message">)" + message + R"(</div>
            </div>
        </main>
        
        <footer class="footer">
            &copy; 2025 StockTrader. All rights reserved.
        </footer>
    </div>
</body>
</html>
    )";
}
