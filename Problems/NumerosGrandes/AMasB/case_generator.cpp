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
    int N;
    Generator::arguments >> N;
    if (N == -1) {
        for (int i = 0; i < 1e5; i++) Generator::case_in << 9;
        Generator::case_in << '\n';
        for (int i = 0; i < 1e5; i++) Generator::case_in << 9;
    } else {
        int k1 = Random::rnd(1, N);
        int k2 = Random::rnd(1, N);

        Generator::case_in << Random::rnd(1, 9);
        for (int i = 1; i < k1; i++) Generator::case_in << Random::rnd(0, 9);

        Generator::case_in << '\n' << Random::rnd(1, 9);
        for (int i = 1; i < k2; i++) Generator::case_in << Random::rnd(0, 9);

    }

    return 0;
}