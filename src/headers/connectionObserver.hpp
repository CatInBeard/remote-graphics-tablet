//  Copyright (c) 2025 Grigoriy Efimov
// 
// Licensed under the MIT License. See LICENSE file for details.

#ifndef CONNECTION_OBSERVER_H

#define CONNECTION_OBSERVER_H

#include <netinet/in.h>
#include <utility>
#include <string>

namespace remoteGraphicsTablet{
    class ConnectionObserver{
        public:
            virtual void notifyConnect(sockaddr_in) = 0;
            virtual void notifyNewMessage(const char*) = 0;
            virtual void notifyDisconnect(sockaddr_in) = 0;
            virtual ~ConnectionObserver(){};
        protected:
            std::pair<std::string, int> getIpAndPortFromSockadrIn(sockaddr_in);
    };
}

#endif