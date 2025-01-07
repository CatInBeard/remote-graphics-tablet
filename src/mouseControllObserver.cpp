//  Copyright (c) 2025 Grigoriy Efimov
// 
// Licensed under the MIT License. See LICENSE file for details.

#include "headers/mouseControllObserver.hpp"
#include "headers/virtualInput.hpp"
#include <iostream>
#include <utility>

namespace remoteGraphicsTablet {

    MouseControllObserver::MouseControllObserver(){
        vInput = std::make_unique<VirtualInput>();
        usleep(1000000); // Delay required for setup
    }

    MouseControllObserver::~MouseControllObserver(){}

    void MouseControllObserver::notifyConnect([[maybe_unused]] sockaddr_in adder){}

    void MouseControllObserver::notifyDisconnect([[maybe_unused]] sockaddr_in adder){}

    void MouseControllObserver::notifyNewMessage(const char* message){
        std::pair<std::string, int> responce = splitString(std::string{message});
        
        if (responce.first == "rx") {
            vInput->move_mouse_rel(responce.second, 0);
        }
        else if (responce.first == "ry") {
            vInput->move_mouse_rel(0, responce.second);
        }
        else if (responce.first == "ml") {
            if(responce.second){
                vInput->start_drag();
            }
            else {
                vInput->end_drag();
            }
        }
    }

    std::pair<std::string, int> MouseControllObserver::splitString(const std::string& input) {
        std::string letters;
        std::string numbers;

        for (char ch : input) {
            if (std::isalpha(ch)) {
                letters += ch;
            } else if (std::isdigit(ch)) {
                numbers += ch;
            }
        }
        return {letters, std::stoi(numbers)};
    }
}