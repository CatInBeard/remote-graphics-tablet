//  Copyright (c) 2025 Grigoriy Efimov
// 
// Licensed under the MIT License. See LICENSE file for details.

#ifndef AUTHORIZATION_CONTROLLER_H

#define AUTHORIZATION_CONTROLLER_H

#include <string>

namespace remoteMouse{
    class AuthorizationController {
        public:
            virtual bool authorize(std::string additionalInfo = "") = 0;
    };
}

#endif