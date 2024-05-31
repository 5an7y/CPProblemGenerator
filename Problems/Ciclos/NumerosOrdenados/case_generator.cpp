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
    int N, ordered;
    Generator::arguments >> N >> ordered;
    if (N == 2 && !ordered) {
        Generator::case_in << "2\n2 1";
    } else {
        Generator::case_in << N << '\n';
        auto vec = Random::rnd(1, 100, N);
        if (ordered) std::sort(vec.begin(), vec.end());
        for (auto& it: vec) Generator::case_in << it << ' ';
    }

    if (ordered) Generator::case_out << "Si";
    else Generator::case_out << "No";

    return 0;
}