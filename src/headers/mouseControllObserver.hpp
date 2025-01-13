//  Copyright (c) 2025 Grigoriy Efimov
// 
// Licensed under the MIT License. See LICENSE file for details.

#ifndef MOUSE_CONTROLL_OBSERVER_H

#define MOUSE_CONTROLL_OBSERVER_H

#include "connectionObserver.hpp"
#include "virtualInput.hpp"
#include "virtualInput.hpp"
#include <list>
#include <memory>

namespace remoteMouse{
    class MouseControllObserver : public ConnectionObserver{
        public:
            MouseControllObserver(std::string mouseName);
            MouseControllObserver();
            virtual ~MouseControllObserver();
            virtual void notifyConnect(sockaddr_in, Server*, int client_fd) override;
            virtual void notifyNewMessage(const char*, Server*, int client_fd) override;
            virtual void notifyDisconnect(sockaddr_in, Server*) override;
        protected:
            std::list<std::pair<std::string, int>> splitString(const std::string&);
            std::unique_ptr<VirtualInput> vInput;
    };
}

#endif