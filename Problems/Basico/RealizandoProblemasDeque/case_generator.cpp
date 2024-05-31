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
    std::string type;
    int N, K;
    Generator::arguments >> type >> N;
    std::vector<int> vec;

    if (type == "RAND") {
        K = Random::rnd(10, 100);
        vec = Random::rnd(1, 100, N);
    } else if (type == "LESS") {
        K = Random::rnd(2, 100);
        vec = Random::rnd(1, K-1, N);
    } else if (type == "GREAT") {
        K = Random::rnd(1, 100);
        vec = Random::rnd(K, 100, N);
    } else {
        K = Random::rnd(2, 100);
        vec = Random::rnd(1, 100, N);
        vec[0] = Random::rnd(K, 100);
        vec[N-1] = Random::rnd(K, 100);
    }

    Generator::case_in << N << ' ' << K << '\n';
    for (auto& it : vec) Generator::case_in << it << ' ';

    return 0;
}