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
    int N, S;
    Generator::arguments >> N >> S;
    auto vec = Random::rnd_unique(1, S, N);

    Generator::case_in << N << '\n';
    for (auto& it : vec)
        Generator::case_in << it << " ";

    Generator::case_in << '\n' << S;

    return 0;
}