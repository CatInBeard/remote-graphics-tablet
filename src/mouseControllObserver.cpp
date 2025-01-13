//  Copyright (c) 2025 Grigoriy Efimov
// 
// Licensed under the MIT License. See LICENSE file for details.

#include "headers/mouseControllObserver.hpp"
#include "headers/server.hpp"
#include "headers/virtualInput.hpp"
#include <utility>

namespace remoteMouse {

    MouseControllObserver::MouseControllObserver(std::string mouseName){
        vInput = std::make_unique<VirtualInput>(mouseName);
    }

    MouseControllObserver::MouseControllObserver(): MouseControllObserver("Virtual mouse"){}

    MouseControllObserver::~MouseControllObserver(){}

    void MouseControllObserver::notifyConnect([[maybe_unused]] sockaddr_in adder, [[maybe_unused]] Server*, [[maybe_unused]] int client_fd){}

    void MouseControllObserver::notifyDisconnect([[maybe_unused]] sockaddr_in adder, Server* server){
        server->unsubscribeObserver(this);
    }

    void MouseControllObserver::notifyNewMessage(const char* message, [[maybe_unused]] Server*, [[maybe_unused]] int client_fd){
        std::list<std::pair<std::string, int>> commands = splitString(std::string{message});

        for(std::pair<std::string, int> command: commands ){
        
            if (command.first == "rx") {
                vInput->move_mouse_rel(command.second, 0);
            }
            else if (command.first == "ry") {
                vInput->move_mouse_rel(0, command.second);
            }
            else if (command.first == "ml") {
                if(command.second){
                    vInput->start_drag();
                }
                else {
                    vInput->end_drag();
                }
            }
            else if (command.first == "mr") {
                if(command.second){
                    vInput->start_drag_right();
                }
                else {
                    vInput->end_drag_right();
                }
            }
            else if (command.first == "mm") {
                if(command.second){
                    vInput->start_drag_middle();
                }
                else {
                    vInput->end_drag_middle();
                }
            }
        }
    }

    std::list<std::pair<std::string, int>> MouseControllObserver::splitString(const std::string& input) {

        std::list<std::pair<std::string, int>> commands;

        std::string letters;
        std::string numbers;

        int numbersInt = 0;

        for (char ch : input) {
            if (std::isalpha(ch)) {
                if(numbers.length()){
                    try{
                        numbersInt = std::stoi(numbers);
                    }
                    catch(const std::exception& e ){
                        numbersInt = 0;
                    }
                    commands.push_back({letters, numbersInt});
                    numbers.clear();
                    letters.clear();
                }
                letters += ch;
            } else if (std::isdigit(ch) || ch == '-') {
                numbers += ch;
            }
        }

        if(numbers.length() && letters.length()){
            try{
                numbersInt = std::stoi(numbers);
            }
            catch(const std::exception& e ){
                numbersInt = 0;
            }
            commands.push_back({letters, numbersInt});
        }
        
        return commands;
    }
}