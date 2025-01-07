//  Copyright (c) 2025 Grigoriy Efimov
// 
// Licensed under the MIT License. See LICENSE file for details.

#include "headers/server.hpp"
#include "headers/connectionObserver.hpp"
#include "headers/connectionTypes.hpp"
#include <stdexcept>

namespace remoteGraphicsTablet {
    Server::Server(int port, ConnectionTypes connectionType){
        server_fd = createSocket(port, connectionType);
    }

    Server::Server() : Server(5123, ConnectionTypes::tcp){};

    Server::~Server(){
        if(server_fd){
            shutdown(server_fd, SHUT_RDWR);
        }
    }
    
    int Server::createSocket(int port, ConnectionTypes connectionType){
        struct sockaddr_in address;

        int socket_fd {};
        switch (connectionType) {
            case ConnectionTypes::udp :
                socket_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
                break;
            default: // TCP
                socket_fd = socket(AF_INET, SOCK_STREAM, 0);
        }
        if (socket_fd <= 0) {
            throw std::runtime_error("Failed to create socket");
        }
        int opt = 1;
        if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
            throw std::runtime_error("Failed to setsockopt");
        }

        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(port);

        if (bind(socket_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
            throw std::runtime_error("Failed to bind port");
        }

        return socket_fd;
    }

    void Server::serve(){
        if (listen(server_fd, 1) < 0) {
            throw std::runtime_error("Failed to start listening");
        }
        for (;;) {
            char *buffer[BUFFER_SIZE];
            int client_fd;
            struct sockaddr_in address;
            socklen_t addrlen = sizeof(sockaddr_in);
            
            if ((client_fd = accept(server_fd, (struct sockaddr *) &address, &addrlen)) < 0) {
                throw std::runtime_error("Failed to accept connection");
            }
            
            for(const auto& observer: observers){
                observer->notifyConnect(address);
            }
            
            for (;;) {
                if(read(client_fd, buffer, BUFFER_SIZE) == 0){
                    break;
                }
                for(const auto& observer: observers){
                    observer->notifyNewMessage( (char *) buffer);
                }
            }

            for(const auto& observer: observers){
                observer->notifyDisconnect(address);
            }
            close(client_fd);
        }
    }

    void Server::addObserver(std::unique_ptr<ConnectionObserver> observer){
        observers.push_back(std::move(observer));
    }

    void Server::resetObservers(){
        observers.clear();
    }

}