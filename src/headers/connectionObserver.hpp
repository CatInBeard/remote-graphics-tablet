//  Copyright (c) 2025 Grigoriy Efimov
// 
// Licensed under the MIT License. See LICENSE file for details.

#ifndef CONNECTION_OBSERVER_H

#define CONNECTION_OBSERVER_H

#include <netinet/in.h>
#include <utility>
#include <string>

namespace remoteMouse{
    class Server;
    class ConnectionObserver{
        public:
            virtual void notifyConnect(sockaddr_in, Server*, int client_fd) = 0;
            virtual void notifyNewMessage(const char*, Server*, int client_fd) = 0;
            virtual void notifyDisconnect(sockaddr_in, Server*) = 0;
            virtual ~ConnectionObserver(){};
        protected:
            std::pair<std::string, int> getIpAndPortFromSockadrIn(sockaddr_in);
    };
}

#endif