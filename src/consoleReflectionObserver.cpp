//  Copyright (c) 2025 Grigoriy Efimov
// 
// Licensed under the MIT License. See LICENSE file for details.

#include "headers/consoleReflectionObserver.hpp"
#include <iostream>

namespace remoteGraphicsTablet {
    void ConsoleReflectionObserver::notifyConnect(sockaddr_in adder){
        std::pair<std::string, int> addr = getIpAndPortFromSockadrIn(adder);
        std::cout << "Connection with " << addr.first << ":" << addr.second << " established.." << std::endl;
    }
    void ConsoleReflectionObserver::notifyDisconnect(sockaddr_in adder){
        std::pair<std::string, int> addr = getIpAndPortFromSockadrIn(adder);
        std::cout << "Diconnect from " << addr.first << ":" << addr.second << "." << std::endl;
    }
    void ConsoleReflectionObserver::notifyNewMessage(const char* message){
        std::cout << "Message received:" << message << std::endl;
    }
}