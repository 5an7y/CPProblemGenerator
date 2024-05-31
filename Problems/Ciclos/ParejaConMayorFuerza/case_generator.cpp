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
    int N, l, r;
    Generator::arguments >> N >> l >> r;

    auto vec = Random::rnd(l, r, N);
    Generator::case_in << N << '\n';
    for (auto& xi : vec)
        Generator::case_in << xi << ' ';
    
    sort(vec.begin(), vec.end());

    Generator::case_out << std::max(abs(vec[0] + vec[1]), abs(vec[N-1] + vec[N-2]));
    return 0;
}