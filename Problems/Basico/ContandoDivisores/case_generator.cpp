#include <iostream>
#include "Generator.hpp"

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
        Use Generator::case_in<< to put elements in case input.
        Use Generator::case_out<< to put elements in case output.
        Use Generator::arguments>> to read the arguments.
    */
    int k, a, b;
    Generator::arguments >> k >> a >> b;
    Generator::case_in << k << ' ' << a << ' ' << b;
    Generator::case_out << b / k - (a - 1) / k;

    return 0;
}