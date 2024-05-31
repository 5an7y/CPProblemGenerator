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
    int N, K;
    Generator::arguments >> N >> K;
    Generator::case_in << N << '\n';
    auto vec = Random::rnd(1, 100, N);
    auto queries = Random::rnd_pair(1, N, K);

    for (auto& it : vec) 
        Generator::case_in << it << " ";
    
    Generator::case_in << '\n' << K << '\n';

    for (auto& [a, b] : queries) {
        int l = std::min(a, b);
        int r = std::max(a, b);
        Generator::case_in << l << " " << r << '\n';
        for (int i = l-1; i < r; i++) vec[i]++;
    }

    for (auto& it : vec) 
        Generator::case_out << it << " ";

    return 0;
}