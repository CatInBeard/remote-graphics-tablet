//  Copyright (c) 2025 Grigoriy Efimov
// 
// Licensed under the MIT License. See LICENSE file for details.

#include "headers/cli.hpp"

#include "headers/CLIAuthorizationController.hpp"
#include "headers/communicationControllObserver.hpp"
#include "headers/iptools.hpp"
#include "headers/consoleReflectionObserver.hpp"
#include "headers/server.hpp"
#include <exception>
#include <iostream>
#include <memory>
#include <ostream>

namespace remoteMouse{

    CLI::CLI(int argc, char** argv){
        this->argc = argc;
        this->argv = argv;
    }

    int CLI::run(){

        int port = 5123;
        bool requireAuth = true;
        bool debug = false;
        std::string deviceName = "remote_mouse";

        std::string arg;
        for(int i=0; i< argc; i++){
            arg = argv[i];
            if(arg == "-h" || arg == "--help"){
                displayHelp();
                return 0;
            }
            else if(arg == "-n" || arg == "--noauth"){
                requireAuth = false;
            }
            else if(arg == "-p" || arg == "--port"){
                if(i+1<argc){
                    try{
                        port = std::stoi(argv[i+1]);
                    } catch (const std::exception& e) {
                        std::cerr << "Port must be a number from 1024 to 65535" << std::endl;
                        return 1;
                    }
                    if(port < 0 || port > 65535){
                        std::cerr << "Port must be a number from 1024 to 65535" << std::endl;
                        return 1;
                    }
                    i++; continue;
                }
                else{
                    std::cerr << "Port must be a number from 1024 to 65535" << std::endl;
                    return 1;
                }

            }
            else if(arg == "-d" || arg == "--devicename"){
                if(i+1<argc){
                    deviceName = argv[i+1];
                    i++; continue;
                }
                else{
                    std::cerr << "Please insert device name after " << arg << std::endl;
                    return 1;
                }

            }
            else if(arg == "-D" || arg == "--debug"){
                debug = true;
            }
        }


        Server server {port};

        std::cout << "Remote mouse avaible on: " << std::endl;

        for(auto ip: getMyIpList()){
            std::cout << ip << ":" << port << std::endl;
        }

        server.addObserver(std::make_unique<CommunicationControllObserver>(std::make_unique<CLIAuthorizationController>() ,!requireAuth, deviceName));
        if(debug){
            server.addObserver(std::make_unique<ConsoleReflectionObserver>());
        }
        server.serve();

        return 0;
    }

    void CLI::displayHelp(){
        std::cout << "This utility allows you to control a virtual mouse/touchpad/graphics tablet from another computer, phone, or tablet." << std::endl << std::endl<<
        "Options:" << std::endl <<
        "-h, --help\tShow this help message and exit" <<std::endl <<
        "-n, --noauth\tDisable authentication and allow automatic connection" << std::endl <<
        "-p, --port <port>   Specify the port to listen on (default: 5123)" << std::endl <<
        "-d, --devicename <name>  Set the name of the virtual mouse device" << std::endl <<
        "-D, --debug Display debug print" << std::endl << std::endl <<
        "License:" << std::endl << 
        "This program is licensed under the MIT License." << std::endl << std::endl <<
        "Examples:" << std::endl <<
        argv[0] << " -p 5123  # Start the server on port 5123" << std::endl <<
        argv[0] << " -n -d \"My Virtual Mouse\"  # Start the server with automatic connection and custom device name" << std::endl;
    }
}