//  Copyright (c) 2025 Grigoriy Efimov
// 
// Licensed under the MIT License. See LICENSE file for details.

#include "headers/mouseControllObserver.hpp"
#include "headers/server.hpp"
#include "headers/virtualInput.hpp"
#include <iostream>
#include <utility>

namespace remoteMouse {

    MouseControllObserver::MouseControllObserver(std::string mouseName){
        vInput = std::make_unique<VirtualInput>(mouseName);
        usleep(1000000); // Delay required for setup
    }

    MouseControllObserver::MouseControllObserver(): MouseControllObserver("Virtual mouse"){}

    MouseControllObserver::~MouseControllObserver(){}

    void MouseControllObserver::notifyConnect([[maybe_unused]] sockaddr_in adder, [[maybe_unused]] Server*, [[maybe_unused]] int client_fd){}

    void MouseControllObserver::notifyDisconnect([[maybe_unused]] sockaddr_in adder, Server* server){
        server->unsubscribeObserver(this);
    }

    void MouseControllObserver::notifyNewMessage(const char* message, [[maybe_unused]] Server*, [[maybe_unused]] int client_fd){
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
        else if (responce.first == "mr") {
            if(responce.second){
                vInput->start_drag_right();
            }
            else {
                vInput->end_drag_right();
            }
        }
        else if (responce.first == "mm") {
            if(responce.second){
                vInput->start_drag_middle();
            }
            else {
                vInput->end_drag_middle();
            }
        }
    }

    std::pair<std::string, int> MouseControllObserver::splitString(const std::string& input) {
        std::string letters;
        std::string numbers;

        for (char ch : input) {
            if (std::isalpha(ch)) {
                letters += ch;
            } else if (std::isdigit(ch) || ch == '-') {
                numbers += ch;
            }
        }

        int numbersInt = 0;

        try{
            numbersInt = std::stoi(numbers);
        }
        catch(const std::exception& e ){
            numbersInt = 0;
        }
        
        return {letters, numbersInt};
    }
}