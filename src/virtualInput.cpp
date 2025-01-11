//  Copyright (c) 2025 Grigoriy Efimov
// 
// Licensed under the MIT License. See LICENSE file for details.

#include "headers/virtualInput.hpp"
#include <iostream>
#include <linux/input-event-codes.h>
#include <cstring>
#include <cerrno>


namespace remoteMouse {
    VirtualInput::VirtualInput(std::string deviceName){
        deviceFD = create_uinput_device(deviceName);
        send_sync();
    }

    VirtualInput::VirtualInput() : VirtualInput("Virtual input") {}

    void VirtualInput::move_mouse_rel(int x, int y) {
        if(x != 0){
            send_event(EV_REL, REL_X, x);
        }
        if(y != 0){
            send_event(EV_REL, REL_Y, y);
        }
        send_sync();
    }

    void VirtualInput::move_mouse_abs(int x, int y) {
        send_event(EV_ABS, ABS_X, x);
        send_event(EV_ABS, ABS_Y, y);
        send_sync();
    }

    void VirtualInput::start_drag() {
        VirtualInput::click_mouse(BTN_LEFT, 1);
        send_sync();
    }

    void VirtualInput::start_drag_right() {
        VirtualInput::click_mouse(BTN_RIGHT, 1);
        send_sync();
    }

    void VirtualInput::start_drag_middle() {
        VirtualInput::click_mouse(BTN_MIDDLE, 1);
        send_sync();
    }

    void VirtualInput::end_drag() {
        VirtualInput::click_mouse(BTN_LEFT, 0);
        send_sync();
    }

    void VirtualInput::end_drag_right() {
        VirtualInput::click_mouse(BTN_RIGHT, 0);
        send_sync();
    }

    void VirtualInput::end_drag_middle() {
        VirtualInput::click_mouse(BTN_MIDDLE, 0);
        send_sync();
    }

    void VirtualInput::click_mouse_left() {
        click_mouse(BTN_LEFT, 1);
        click_mouse(BTN_LEFT, 0);
        send_sync();
    }

    void VirtualInput::click_mouse_right() {
        click_mouse(BTN_LEFT, 1);
        click_mouse(BTN_LEFT, 0);
        send_sync();
    }

    void VirtualInput::click_mouse_middle() {
        click_mouse(BTN_MIDDLE, 1);
        click_mouse(BTN_MIDDLE, 0);
        send_sync();
    }

    VirtualInput::~VirtualInput(){
        close(deviceFD);
    }
    
    int VirtualInput::create_uinput_device(const std::string& name) {
        int fd;
        struct uinput_user_dev uidev;

        fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
        if (fd < 0) {
            throw std::runtime_error("Can't open /dev/uinput");
        }

        memset(&uidev, 0, sizeof(uidev));
        snprintf(uidev.name, UINPUT_MAX_NAME_SIZE, "%s", name.c_str());
        uidev.id.bustype = BUS_USB;
        uidev.id.vendor = 0x1234;
        uidev.id.product = 0x5678;
        uidev.id.version = 1;


        // Allowed events
        // EV_SYN
        ioctl(fd, UI_SET_EVBIT, EV_SYN);

        // EV_KEY
        ioctl(fd, UI_SET_EVBIT, EV_KEY);
        ioctl(fd, UI_SET_KEYBIT, BTN_LEFT);
        ioctl(fd, UI_SET_KEYBIT, BTN_RIGHT);
        ioctl(fd, UI_SET_KEYBIT, BTN_MIDDLE);
        ioctl(fd, UI_SET_KEYBIT, BTN_SIDE);
        ioctl(fd, UI_SET_KEYBIT, BTN_EXTRA);
        ioctl(fd, UI_SET_KEYBIT, BTN_FORWARD);
        ioctl(fd, UI_SET_KEYBIT, BTN_BACK);
        ioctl(fd, UI_SET_KEYBIT, BTN_TASK);
        
        // EV_REL
        ioctl(fd, UI_SET_EVBIT, EV_REL);
        ioctl(fd, UI_SET_RELBIT, REL_X);
        ioctl(fd, UI_SET_RELBIT, REL_Y);
        ioctl(fd, UI_SET_RELBIT, REL_HWHEEL);
        ioctl(fd, UI_SET_RELBIT, REL_WHEEL);
        ioctl(fd, UI_SET_RELBIT, REL_WHEEL_HI_RES);
        ioctl(fd, UI_SET_RELBIT, REL_HWHEEL_HI_RES);


        // Save settings
        if (write(fd, &uidev, sizeof(uidev)) < 0) {
            throw std::runtime_error("Can't update /dev/uinput");
        }

        // Create device
        if (ioctl(fd, UI_DEV_CREATE) < 0) {
            throw std::runtime_error("Can't create virtual device");
        }

        return fd; // Return descripter
    }
    
    void VirtualInput::send_event(int type, int code, int value) {
        struct input_event ev;
        memset(&ev, 0, sizeof(ev));
        ev.type = type;
        ev.code = code;
        ev.value = value;
        if (write(deviceFD, &ev, sizeof(ev)) < 0) {
            throw std::runtime_error("Can't write event");
        }
    }

    void VirtualInput::send_sync(){
        send_event(EV_SYN, SYN_REPORT, 0);
    }

    void VirtualInput::click_mouse(int button, int press) {
        send_event(EV_KEY, button, press);
    }
}