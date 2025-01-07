//  Copyright (c) 2025 Grigoriy Efimov
// 
// Licensed under the MIT License. See LICENSE file for details.

#ifndef MOUSE_CONTROLL_OBSERVER_H

#define MOUSE_CONTROLL_OBSERVER_H

#include "connectionObserver.hpp"
#include "virtualInput.hpp"
#include "virtualInput.hpp"
#include <memory>

namespace remoteGraphicsTablet{
    class MouseControllObserver : public ConnectionObserver{
        public:
            MouseControllObserver();
            virtual ~MouseControllObserver();
            virtual void notifyConnect(sockaddr_in) override;
            virtual void notifyNewMessage(const char*) override;
            virtual void notifyDisconnect(sockaddr_in) override;
        protected:
            std::pair<std::string, int> splitString(const std::string&);
            std::unique_ptr<VirtualInput> vInput;
    };
}

#endif