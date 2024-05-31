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
    int N, K;
    Generator::arguments >> type >> N >> K;
    std::vector<int> vec;
    if (type == "NO") {
        vec = Random::rnd_unique(1, K/2, N);
        for (auto& it : vec) {
            if (Random::rnd(0,1)) {
                it = K - it;
            }
        }
        if (N == 30) vec.push_back(70), N++; 
    } else if (type == "MID") {
        vec = Random::rnd_unique(1, K/2, N-2);
        for (auto& it : vec) {
            if (Random::rnd(0,1)) {
                it = K - it;
            }
        }
        vec.push_back(K/2);
        vec.push_back(K/2);
        std::random_shuffle(vec.begin(), vec.end());
    } else {
        vec = Random::rnd(1, 200, N);
    }
    Generator::case_in << N << " " << K << '\n';
    for (auto& it : vec) Generator::case_in << it << ' ';

    return 0;
}