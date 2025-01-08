//  Copyright (c) 2025 Grigoriy Efimov
// 
// Licensed under the MIT License. See LICENSE file for details.

#include "headers/CLIAuthorizationController.hpp"
#include <iostream>

namespace remoteMouse {
    bool CLIAuthorizationController::authorize(std::string additionalInfo){
        std::cout << std::endl << "New connection request " << additionalInfo << std::endl <<
        "Do you want to accept this connection y/n?" << std::endl;
        std::string c;
        std::cin >> c;
        if(c == "y" || c == "Y") {
            std::cout << "Conncetion accepted" << std::endl;
            return true;
        }
        std::cout << "Conncetion rejected" << std::endl;
        return false;
    }
}