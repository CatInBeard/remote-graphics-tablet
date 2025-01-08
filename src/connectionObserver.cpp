//  Copyright (c) 2025 Grigoriy Efimov
// 
// Licensed under the MIT License. See LICENSE file for details.

#include "headers/connectionObserver.hpp"
#include <arpa/inet.h>
#include <string>
#include <utility>

namespace remoteMouse{
    std::pair<std::string, int> ConnectionObserver::getIpAndPortFromSockadrIn(sockaddr_in address){
        char ip_str[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &address.sin_addr, ip_str, sizeof(ip_str));
        int client_port = ntohs(address.sin_port);
        return std::pair<std::string, int> {ip_str, client_port};
    }
}