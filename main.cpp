// main.cpp
#include <crow/app.h>
#include "model.hpp"
#include "controller.hpp"

int main(int argc, char* argv[]) {
    crow::SimpleApp app;
    UserModel model;

    AppController::setupRoutes(app, model);

    int port = 18080; // default port
    if (argc > 1) {
        port = std::atoi(argv[1]); // convert first arg to int
    }
    app.port(port).multithreaded().run();
}
