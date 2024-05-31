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
    int N, M;
    Generator::arguments >> N >> M;
    Generator::case_in << N << " " << M << '\n';
    std::vector<std::vector<int>> mat(N);
    for (auto& vec : mat) {
        vec = Random::rnd(1, 4, M);
        for (auto& it : vec) {
            Generator::case_in << (int)(it == 1) << ' ';
        }
        Generator::case_in << '\n';
    }

    return 0;
}