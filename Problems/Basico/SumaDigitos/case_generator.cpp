#include <iostream>
#include "Generator.hpp"

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
        Use Generator::case_in<< to put elements in case input.
        Use Generator::case_out<< to put elements in case output.
        Use Generator::arguments>> to read the arguments.
    */
    int A;
    Generator::arguments >> A;
    Generator::case_in << A;
    int suma = 0;
    while (A) {
        suma += A % 10;
        A /= 10;
    }
    Generator::case_out << suma;

    return 0;
}