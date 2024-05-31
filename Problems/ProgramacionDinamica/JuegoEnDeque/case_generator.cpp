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
    int maxn, maxai; std::string type_case;
    Generator::arguments >> maxn >> maxai >> type_case;
    int N = Random::rnd(1, maxn);
    auto vec = Random::rnd(1, maxai, N);
    if (type_case == "SPECIAL")
        for (int i = 0; i < N; i++) vec[i] = maxai * (i % 2) + (1 - i % 2);
    
    Generator::case_in << N << '\n';
    for (auto& it : vec) Generator::case_in << it << '\n';

    return 0;
}