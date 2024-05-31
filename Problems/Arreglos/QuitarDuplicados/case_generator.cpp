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
    int N;
    Generator::arguments >> N;
    Generator::case_in << N << '\n';
    auto vec = Random::rnd(1, 100, N);
    std::sort(vec.begin(), vec.end());
    for (auto& it: vec) Generator::case_in << it << ' ';
    for (int i = 0; i < N; i++) {
        if (i == 0 || vec[i] != vec[i-1])
            Generator::case_out << vec[i] << ' ';
    }

    return 0;
}