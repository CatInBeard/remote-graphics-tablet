//  Copyright (c) 2025 Grigoriy Efimov
// 
// Licensed under the MIT License. See LICENSE file for details.

#include "headers/iptools.hpp"

namespace remoteMouse {

    std::list<std::string> getMyIpList() {
        struct ifaddrs *ifaddr, *ifa;
        int s;
        char host[NI_MAXHOST];

        std::list<std::string> ip_list;
        
        if (getifaddrs(&ifaddr) == -1) {
            throw std::runtime_error("Can't get interfaces");
        }

        for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
            if (ifa->ifa_addr && (ifa->ifa_addr->sa_family == AF_INET || ifa->ifa_addr->sa_family == AF_INET6)) {
                if ((ifa->ifa_flags & IFF_UP) && (ifa->ifa_flags & IFF_RUNNING)) {
                    if (ifa->ifa_flags & IFF_BROADCAST) {
                        s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
                        if (s != 0) {
                            continue;
                        }
                        
                        ip_list.push_back({host});    
                    } 
                    else if (std::string(ifa->ifa_name) == "wlan0") {
                        s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
                        if (s != 0) {
                            continue;
                        }

                        ip_list.push_back({host});    
                    }
                }
            }
        }

        freeifaddrs(ifaddr);

        return ip_list;
    }

}