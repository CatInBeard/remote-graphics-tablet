//  Copyright (c) 2025 Grigoriy Efimov
// 
// Licensed under the MIT License. See LICENSE file for details.

#ifndef CONSOLE_REFLECTION_OBSERVER_H

#define CONSOLE_REFLECTION_OBSERVER_H

#include "connectionObserver.hpp"

namespace remoteMouse{
    class ConsoleReflectionObserver : public ConnectionObserver{
        public:
            virtual void notifyConnect(sockaddr_in, Server*, int client_fd) override;
            virtual void notifyNewMessage(const char*, Server*, int client_fd) override;
            virtual void notifyDisconnect(sockaddr_in, Server*) override;
    };
}

#endif