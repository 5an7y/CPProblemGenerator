#pragma once

#include <iostream>
#include <exception>
#include <string>
#include <sstream>

namespace Generator {
    void init_generator(int argc, char *argv[]) {
        if (argc <= 2) 
            throw std::invalid_argument("Missing requiered argument \"case_name\"");
        
        freopen(argv[1], "w", stdout);
        
        if (argc > 2) {
            std::string S(argv[2]);
            for (int i = 3; i < argc; i++) {
                std::string B(argv[i]);
                S = S + " " + B;
            }
            std::istringstream buf(S);
            std::cin.rdbuf(buf.rdbuf());
        }

        return;
    }
}