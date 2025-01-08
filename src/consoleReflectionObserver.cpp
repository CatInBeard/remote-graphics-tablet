//  Copyright (c) 2025 Grigoriy Efimov
// 
// Licensed under the MIT License. See LICENSE file for details.

#include "headers/consoleReflectionObserver.hpp"
#include <iostream>

namespace remoteMouse {
    void ConsoleReflectionObserver::notifyConnect(sockaddr_in adder, [[maybe_unused]] Server*, [[maybe_unused]] int client_fd){
        std::pair<std::string, int> addr = getIpAndPortFromSockadrIn(adder);
        std::cout << "Connection with " << addr.first << ":" << addr.second << " established.." << std::endl;
    }
    void ConsoleReflectionObserver::notifyDisconnect(sockaddr_in adder, [[maybe_unused]] Server*){
        std::pair<std::string, int> addr = getIpAndPortFromSockadrIn(adder);
        std::cout << "Diconnect from " << addr.first << ":" << addr.second << "." << std::endl;
    }
    void ConsoleReflectionObserver::notifyNewMessage(const char* message, [[maybe_unused]] Server*, [[maybe_unused]] int client_fd){
        std::cout << "Message received:" << message << std::endl;
    }
}