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
        for (int i = 1; i < N; i++) vec[i-1] = i;
        std::random_shuffle(vec.begin(), vec.end());
    } else {
        vec = Random::rnd(1, K, N);
    }
    Generator::case_in << N << '\n';
    for (auto& it : vec) Generator::case_in << it << ' ';

    return 0;
}