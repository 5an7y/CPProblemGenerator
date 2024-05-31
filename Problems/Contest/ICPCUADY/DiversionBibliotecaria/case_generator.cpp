#include <iostream>
#include "Generator.hpp"
#include "Random.hpp"
#include "Constants.hpp" 

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
        Use Generator::case_in<< to put elements in case input.
        Use Generator::case_out<< to put elements in case output.
        Use Generator::arguments>> to read the arguments.
    */
    int N;
    std::string type, a;
    Generator::arguments >> N >> type;
    int K = Constants::uppercaseEnglishAlphabet.size();
    if (type == "SAME") {
        int r = Random::rnd(0, K-1);
        for (int i = 0; i < N; i++) 
            a += Constants::uppercaseEnglishAlphabet[r];
    } else if (type == "DIFF") {
        auto vec = Random::rnd_unique(0, K-1, N);
        for (auto& it : vec)
            a += Constants::uppercaseEnglishAlphabet[it];
    } else if (type == "RAND") {
        auto vec = Random::rnd(0, K-1, N);
        for (auto& it : vec)
            a += Constants::uppercaseEnglishAlphabet[it];
    } else if (type == "ODD") {
        auto vec = Random::rnd_nums_that_sum(N, K, true);
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < vec[i]*2 + 1; j++) {
                a += Constants::uppercaseEnglishAlphabet[i];
            }
        }
        std::random_shuffle(a.begin(), a.end());
    } else {
        auto vec = Random::rnd_nums_that_sum(N, K, true);
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < vec[i]*2; j++) {
                a += Constants::uppercaseEnglishAlphabet[i];
            }
        }
        std::random_shuffle(a.begin(), a.end());
    }

    Generator::case_in << a;

    return 0;
}