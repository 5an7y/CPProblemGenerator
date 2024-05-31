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
    int maxn, maxk, maxai;
    Generator::arguments >> maxn >> maxk >> maxai;

    int N, K; std::vector<int> nums;

    if (maxai == -1) {
        N = Random::rnd(1, maxn);
        K = Random::rnd(N, maxk);
        nums = Random::rnd(1, K / N, N);
    } else {
        N = Random::rnd(1, maxn);
        K = Random::rnd(1, maxk);
        nums = Random::rnd(1, maxai, N);
    }

    Generator::case_in << N << " " << K << '\n';
    for (auto& ai : nums) Generator::case_in << ai << ' ';

    return 0;
}