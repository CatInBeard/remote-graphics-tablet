//  Copyright (c) 2025 Grigoriy Efimov
// 
// Licensed under the MIT License. See LICENSE file for details.

#ifndef CLI_AUTHORIZATION_CONTROLLER_H

#define CLI_AUTHORIZATION_CONTROLLER_H

#include "authorizationController.hpp"
#include <string>

namespace remoteMouse{
    class CLIAuthorizationController: public AuthorizationController {
        public:
            virtual bool authorize(std::string additionalInfo = "");
    };
}

#endif