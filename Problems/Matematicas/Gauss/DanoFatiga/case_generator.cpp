#include <iostream>
#include "Generator.hpp"

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
        Use Generator::case_in<< to put elements in case input.
        Use Generator::case_out<< to put elements in case output.
        Use Generator::arguments>> to read the arguments.
    */
    unsigned long long n, m, x;
    Generator::arguments >> n >> m >> x;
    Generator::case_in << n << " " << m << " " << x;

    return 0;
}