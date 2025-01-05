//  Copyright (c) 2025 Grigoriy Efimov
// 
// Licensed under the MIT License. See LICENSE file for details.

#include "headers/virtualInput.hpp"

using namespace remoteGraphicsTablet;

int main() {
    VirtualInput vInput {};
    usleep(100000); // Delay required for setup




    vInput.start_drag();
    for(int i = 0; i < 100; i++){
        vInput.move_mouse_rel(2, 1);
        usleep(10000);
    }
    vInput.end_drag();

    
    return 0;
}
