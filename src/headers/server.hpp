//  Copyright (c) 2025 Grigoriy Efimov
// 
// Licensed under the MIT License. See LICENSE file for details.

#ifndef SERVER_H

#define SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <vector>
#include <memory>

#include "connectionTypes.hpp"
#include "connectionObserver.hpp"

#define BUFFER_SIZE 1024

namespace remoteGraphicsTablet{
    class Server{
        public:
            Server(int port, ConnectionTypes connectionType);
            Server();
            ~Server();
            void addObserver(std::unique_ptr<ConnectionObserver>);
            void resetObservers();
            void serve();
        protected:
            int createSocket(int port, ConnectionTypes connectionType);
            int server_fd;
            std::vector<std::unique_ptr<ConnectionObserver>> observers;
    };
}

#endif