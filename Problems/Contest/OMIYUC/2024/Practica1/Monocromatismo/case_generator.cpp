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
    int N, K; std::string type;
    Generator::arguments >> N >> K >> type;
    std::vector<int> vi;
    if (type == "RAND") {
        vi = Random::rnd(1, K, N);
    } else if (type == "ORDERED") {
        for (int i = 1; i <= K; i++)
            vi.push_back(i);
    } else if (type == "UP") {
        vi = Random::rnd(1+K/10, K, N);
    } else if (type == "DOWN") {
        vi = Random::rnd(1, K - K / 10, N);
    } else if (type== "PER") {
        for (int i = 1; i <= K; i++)
            vi.push_back(i);
        std::random_shuffle(vi.begin(), vi.end());
    }

    Generator::case_in << N << ' ' << K << '\n';
    for(auto& xi : vi) Generator::case_in << xi << ' ';

    return 0;
}