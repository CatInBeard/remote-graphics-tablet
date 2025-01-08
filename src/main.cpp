//  Copyright (c) 2025 Grigoriy Efimov
// 
// Licensed under the MIT License. See LICENSE file for details.

#include "headers/cli.hpp"

using namespace remoteMouse;

int main(int argc, char* argv[]) {

    CLI cli {argc, argv};

    return cli.run();
}
