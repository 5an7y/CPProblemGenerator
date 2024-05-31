#include <iostream>
#include "Generator.hpp"

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
        Use Generator::case_in<< to put elements in case input.
        Use Generator::case_out<< to put elements in case output.
        Use Generator::arguments>> to read the arguments.
    */
    int K;
    Generator::arguments >> K;
    Generator::case_in << K << '\n';
    for (int i = 2; i < K; i++) {
        if (K % i == 0) {
            Generator::case_out << "No";
            return 0;
        }
    }
    Generator::case_out << "Si";

    return 0;
}