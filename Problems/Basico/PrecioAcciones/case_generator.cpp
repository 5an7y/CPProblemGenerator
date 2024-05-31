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
    auto vec = Random::rnd(1, 100, N);
    if (type == "SORTED") {
        std::sort(vec.begin(), vec.end());
    } else if (type == "INV") {
        std::sort(vec.begin(), vec.end());
        std::reverse(vec.begin(), vec.end());
    }
    Generator::case_in << N << '\n';
    for (auto& it : vec) Generator::case_in << it << ' ';
    return 0;
}