//  Copyright (c) 2025 Grigoriy Efimov
// 
// Licensed under the MIT License. See LICENSE file for details.

#ifndef CLI_H

#define CLI_H

namespace remoteMouse{
    class CLI {
        public:
            CLI(int argc, char** argv);
            int run();
            void displayHelp();
        protected:
            int argc;
            char** argv;
    };
}

#endif