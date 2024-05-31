#include <iostream>
#include "Generator.hpp"

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
        Use Generator::case_in<< to put elements in case input.
        Use Generator::case_out<< to put elements in case output.
        Use Generator::arguments>> to read the arguments.
    */
    int N;
    Generator::arguments >> N;
    Generator::case_in << N;
    for (int i = 1; i <= N; i++) Generator::case_out << i << " ";

    return 0;
}