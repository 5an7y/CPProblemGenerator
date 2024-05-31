#include <iostream>
#include <vector>
#include "Random.hpp"
#include "Generator.hpp"

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
        Use Generator::case_in<< to put elements in case input.
        Use Generator::case_out<< to put elements in case output.
        Use Generator::arguments>> to read the arguments.
    */
    int N, M;
    Generator::arguments >> N >> M;
    std::vector<std::vector<int>> matriz(N);
    for (auto& vec : matriz) vec = Random::rnd(1, 100, M);

    Generator::case_in << N << ' ' << M << '\n';
    for (auto& vec : matriz) {
        for (auto& xi : vec) Generator::case_in << xi << ' ';
        Generator::case_in << '\n';
    }

    reverse(matriz.begin(), matriz.end());
    for (auto& vec : matriz) {
        for (auto& xi : vec) Generator::case_out << xi << ' ';
        Generator::case_out << '\n';
    }
    
    return 0;
}