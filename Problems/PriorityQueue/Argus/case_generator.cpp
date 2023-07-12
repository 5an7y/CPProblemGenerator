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
    int N = Random::rnd<int>(1, 1e3),
        K = Random::rnd<int>(1, 1e4);
    auto ids = Random::rnd_unique<int64_t>(1, 1e5, N);
    auto periods = Random::rnd_unique<int64_t>(1, 1e5, N);

    Generator::case_in << N << " " << K << '\n';
    for(int i = 0; i < N; i++)
        Generator::case_in << ids[i] << " " << periods[i] << '\n';

    return 0;
}