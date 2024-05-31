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
    int maxi = 0;
    for (auto& xi : vec) {
        Generator::case_in << xi << ' ';
        maxi = std::max(maxi, xi);
    }
    Generator::case_out << maxi;

    return 0;
}