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
    Generator::case_in << N << ' ' << K << '\n';
    auto vec = Random::rnd(1, 100, N);
    for (auto& xi : vec) Generator::case_in << xi << ' ';

    K %= N;
    for (int i = N - K; i < N; i++) Generator::case_out << vec[i] << ' ';
    for (int i = 0; i < N - K; i++) Generator::case_out << vec[i] << ' ';

    return 0;
}