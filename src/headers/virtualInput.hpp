//  Copyright (c) 2025 Grigoriy Efimov
// 
// Licensed under the MIT License. See LICENSE file for details.

#ifndef VIRTUAL_INPUT_H

#define VIRTUAL_INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/uinput.h>
#include <linux/input.h>
#include <sys/ioctl.h>
#include <stdexcept>
#include <iostream>

namespace remoteMouse{
    class VirtualInput{
        public:
            VirtualInput(std::string);
            VirtualInput();
            ~VirtualInput();
            void start_drag();
            void end_drag();
            void start_drag_right();
            void end_drag_right();
            void start_drag_middle();
            void end_drag_middle();
            void move_mouse_rel(int x, int y);
            void move_mouse_abs(int x, int y);
            void click_mouse_left();
            void click_mouse_right();
            void click_mouse_middle();
        protected:
            int create_uinput_device(const std::string& name);
            void send_event(int type, int code, int value);
            void send_sync();
            void click_mouse(int button, int press);
            int deviceFD = {};
    };
}

#endif