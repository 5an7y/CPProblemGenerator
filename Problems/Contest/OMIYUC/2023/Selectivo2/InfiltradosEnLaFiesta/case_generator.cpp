#include <iostream>

#include "Generator.hpp"
#include "Random.hpp"

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
        Use Generator::case_in<< to put elements in case input.
        Use Generator::case_out<< to put elements in case output.
        Use Generator::arguments>> to read the arguments.
    */
    long long maxN, diff;
    std::string type;

    Generator::arguments >> maxN >> diff;
    long long b = Random::rnd(diff, maxN);
    long long a = b - diff;

    Generator::case_in << a << " " << b;

    return 0;
}