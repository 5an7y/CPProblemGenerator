#include <iostream>
#include <algorithm>
#include "Generator.hpp"
#include "Random.hpp"

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
        Use Generator::case_in<< to put elements in case input.
        Use Generator::case_out<< to put elements in case output.
        Use Generator::arguments>> to read the arguments.
    */
    int maxi = 1e5;
    int N, K;
    Generator::arguments >> N >> K;
    std::vector<int> vec(N);
    for (int i = 0; i < K; i++) vec[i] = maxi;
    for (int i = K; i < N; i++) vec[i] = Random::rnd(1, maxi - 1);
    std::random_shuffle(vec.begin(), vec.end());

    Generator::case_in << N << '\n';
    for (auto& xi : vec)
        Generator::case_in << xi << ' ';

    return 0;
}