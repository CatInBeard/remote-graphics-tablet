//  Copyright (c) 2025 Grigoriy Efimov
// 
// Licensed under the MIT License. See LICENSE file for details.

#ifndef COMMUNICATION_CONTROLL_OBSERVER_H

#define COMMUNICATION_CONTROLL_OBSERVER_H

#include "authorizationController.hpp"
#include "connectionObserver.hpp"
#include <memory>

namespace remoteMouse{
    class CommunicationControllObserver : public ConnectionObserver{
        public:
            CommunicationControllObserver(std::unique_ptr<AuthorizationController> controller,bool skipAuth = false, std::string deviceName = "Virtual input");
            virtual void notifyConnect(sockaddr_in, Server*, int client_fd) override;
            virtual void notifyNewMessage(const char*, Server*, int client_fd) override;
            virtual void notifyDisconnect(sockaddr_in, Server*) override;
        protected:
            std::string trimNewline(std::string str);
            bool isAuthorized = false;
            bool skipAuth;
            std::unique_ptr<AuthorizationController> authController;
            std::string deviceName;
    };
}

#endif