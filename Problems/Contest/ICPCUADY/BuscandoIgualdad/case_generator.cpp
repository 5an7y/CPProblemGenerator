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
    std::vector<int> vec(N);
    if (K == -1) {
        vec = Random::rnd_unique(1, 1000, N);
    } else if (K == 1) {
        int r = Random::rnd(1, 1000);
        vec = Random::rnd(r, r, N);
    } else {
        vec = Random::rnd(1, K, N);
    }

    Generator::case_in << N << '\n';
    for(auto& it : vec) Generator::case_in << it << ' ';

    return 0;
}