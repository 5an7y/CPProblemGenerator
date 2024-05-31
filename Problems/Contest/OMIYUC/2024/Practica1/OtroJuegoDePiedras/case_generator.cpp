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
    std::string aux; 
    Generator::arguments >> aux;
    std::vector<int> vec;
    if (aux == "RAND") {
        vec = Random::rnd(1, K, N);
    } else if (aux == "EQ") {
        int num = Random::rnd(1, K);
        vec.resize(N, num);
    } else if (aux == "ONES") {
        vec.resize(N, 1);
    } else if (aux == "S2") {
        int num = Random::rnd((K + 2) / 2, K - N);
        vec = Random::rnd_nums_that_sum(K - num, N-1);
        vec.push_back(num);
        std::random_shuffle(vec.begin(), vec.end());
    } else if (aux == "E2") {
        int num = K/2;
        vec = Random::rnd_nums_that_sum(K - num, N-1);
        vec.push_back(num);
        std::random_shuffle(vec.begin(), vec.end());
    } else if (aux == "PAR") {
        vec = Random::rnd(1, K, N);
        int64_t s = 0;
        for (auto& xi : vec) s += xi;
        if (s % 2 == 1) vec[0]++;
    } else {
        vec = Random::rnd(1, K, N);
        int64_t s = 0;
        for (auto& xi : vec) s += xi;
        if (s % 2 == 0) vec[0]++;
    }

    Generator::case_in << N << '\n';
    for (auto& xi : vec) Generator::case_in << xi << ' ';

    return 0;
}