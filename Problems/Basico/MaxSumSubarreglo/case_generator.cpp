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
    int N;
    Generator::arguments >> type >> N;
    std::vector<int> vec;
    if (type == "ALLPOS") {
        vec = Random::rnd(1, 100, N);
    } else if (type == "ALLNEG") {
        vec = Random::rnd(-100, -1, N);
    } else {
        vec = Random::rnd(-100, 100, N);
    }
    
    Generator::case_in << N << '\n';
    for (auto& it : vec)
        Generator::case_in << it << ' ';

    return 0;
}