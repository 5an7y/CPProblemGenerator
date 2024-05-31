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
    int N, Q;
    Generator::arguments >> N >> Q;

    auto vec = Random::rnd_unique(1, N, N);
    auto questions = Random::rnd(1, N, Q);
    
    Generator::case_in << N << " " << Q << '\n';
    for(auto& it: vec) Generator::case_in << it << ' ';
    Generator::case_in << '\n';
    for(auto& it: questions) Generator::case_in << it << ' ';

    return 0;
}