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
    int N;
    Generator::arguments >> N;
    auto vec = Random::rnd(1, 100, N);

    Generator::case_in << N << '\n';
    int sum = 0;
    for (auto& it : vec) {
        Generator::case_in << it << ' ';
        sum += it;
    }

    Generator::case_out << sum;
    return 0;
}