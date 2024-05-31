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
    Generator::case_in << N << " " << K << '\n';
    auto vec = Random::rnd(1, 100, N);
    int ans = 0;
    for (auto& it : vec) { 
        if (it < K) ans++;
        Generator::case_in << it << " ";
    }
    Generator::case_out << ans;

    return 0;
}