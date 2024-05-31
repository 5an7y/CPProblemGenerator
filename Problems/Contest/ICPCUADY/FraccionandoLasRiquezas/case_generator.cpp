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
    int N, K;
    Generator::arguments >> N >> K;
    std::vector<int> vec;
    if (K == -1) {
        vec = Random::rnd_unique(1, 1000000, N);
    } else {
        auto sel = Random::rnd_unique(1, 1000000, K);
        vec = Random::rnd(0, K-1, N);
        for (auto& it : vec) it = sel[it];
    }
    Generator::case_in << N << '\n';
    for (auto& it : vec) Generator::case_in << it << ' ';

    return 0;
}