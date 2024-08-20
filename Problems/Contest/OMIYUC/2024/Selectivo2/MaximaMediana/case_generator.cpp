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
    int N, K, Ai, sorted;
    Generator::arguments >> N >> K >> Ai >> sorted;
    auto vec = Random::rnd(1, Ai, N);
    if (sorted) std::sort(vec.begin(), vec.end());
    Generator::case_in << N << ' ' << K << '\n';
    for (auto& it : vec) Generator::case_in << it << ' ';

    return 0;
}