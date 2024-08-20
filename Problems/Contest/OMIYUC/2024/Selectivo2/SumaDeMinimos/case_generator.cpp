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
    std::string aux;
    Generator::arguments >> N >> M >> aux;
    auto vec = Random::rnd(1, M, N);
    if (aux == "PERMUTATION") vec = Random::rnd_unique(1, M, N);
    if (aux == "SORTED") std::sort(vec.begin(), vec.end());
    Generator::case_in << N << '\n';
    for (auto& it : vec) Generator::case_in << it << ' ';
    return 0;
}