#include <iostream>
#include "Generator.hpp"
#include "Random.hpp"
#include <algorithm>

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
        Use Generator::case_in<< to put elements in case input.
        Use Generator::case_out<< to put elements in case output.
        Use Generator::arguments>> to read the arguments.
    */
    int N, K;
    Generator::arguments >> N >> K;
    Generator::case_in << N + K << '\n';
    auto vec = Random::rnd(1, 100, N);
    vec.resize(N + K, 0);
    std::random_shuffle(vec.begin(), vec.end());
    for (auto& it : vec) Generator::case_in << it << " ";
    for (auto& it : vec) if (it != 0) Generator::case_out << it << " ";
    for (auto& it : vec) if (it == 0) Generator::case_out << it << " ";
    
    return 0;
}