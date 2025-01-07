//  Copyright (c) 2025 Grigoriy Efimov
// 
// Licensed under the MIT License. See LICENSE file for details.

#include "headers/consoleReflectionObserver.hpp"
#include "headers/mouseControllObserver.hpp"
#include "headers/virtualInput.hpp"
#include "headers/server.hpp"
#include <memory>

using namespace remoteGraphicsTablet;

int main() {

    Server server {};
    server.addObserver(std::make_unique<ConsoleReflectionObserver>());
    server.addObserver(std::make_unique<MouseControllObserver>());
    server.serve();

    return 0;
}
