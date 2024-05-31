#pragma once

#include <iostream>
#include <exception>
#include <string>
#include <sstream>
#include <fstream>

namespace Generator {
    std::ofstream case_in, case_out;
    std::stringstream arguments;

    void init_generator(int argc, char *argv[]) {
        if (argc < 2) 
            throw std::invalid_argument("Missing requiered argument \"case_name\"");
        
        std::string case_in_name(argv[1]), case_out_name(argv[1]);
        if (case_in_name.back() == '\n') case_in_name.pop_back(), case_out_name.pop_back();
        case_in_name += ".in"; case_out_name += ".out";

        case_in.open(case_in_name.c_str());
        case_out.open(case_out_name.c_str());

        if (!case_in) {
            throw std::runtime_error("Error al abrir " + case_in_name + "\n");
            exit(EXIT_FAILURE);
        }
        if (!case_out) {
            throw std::runtime_error("Error al abrir " + case_out_name + "\n");
            exit(EXIT_FAILURE);
        }
        
        if (argc > 2) {
            for (int i = 2; i < argc; i++) {
                std::string B(argv[i]);
                arguments << B << " \n"[i == argc-1];
            }
        }

        return;
    }
}