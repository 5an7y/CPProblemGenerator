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
    int N, K, Q;
    Generator::arguments >> N >> K >> Q;
    auto vec = Random::rnd(1, K, N);
    auto changes = Random::rnd(1, N, Q);
    auto changesai = Random::rnd(1, K, Q);

    Generator::case_in << N << '\n';
    for (auto& it : vec) Generator::case_in << it << ' ';
    Generator::case_in << '\n' << Q << '\n';
    for (int i = 0; i < Q; i++)
        Generator::case_in << changes[i] << ' ' << changesai[i] << '\n';
    

    return 0;
}