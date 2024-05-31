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
    auto vec = Random::rnd(1, K, N);
    Generator::case_in << N << '\n';
    for (auto& it : vec) Generator::case_in << it << ' ';
    Generator::case_out << vec[N-1] << ' ';
    for (int i = 0; i < N-1; i++)
        Generator::case_out << vec[i] << ' ';

    return 0;
}