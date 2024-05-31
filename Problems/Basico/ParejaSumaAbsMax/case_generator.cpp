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
    std::string type; int N;
    Generator::arguments >> type >> N;

    Generator::case_in << N << '\n';
    if (type == "RAND") {
        auto vec = Random::rnd(-100, 100, N);
        for (auto& it : vec) 
            Generator::case_in << it << ' ';
    } else {
        auto vec = Random::rnd_unique(-100, 100, N);
        for (auto& it : vec)
            Generator::case_in << it << ' ';
    }

    return 0;
}