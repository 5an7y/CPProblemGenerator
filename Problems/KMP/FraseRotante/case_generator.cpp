#include <iostream>
#include "Generator.hpp"
#include "Constants.hpp"
#include "Random.hpp"

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
        Use Generator::case_in<< to put elements in case input.
        Use Generator::case_out<< to put elements in case output.
        Use Generator::arguments>> to read the arguments.
    */
    int N = Random::rnd(1, (int)1e5);
    int K = Random::rnd(0, N - 1);
    std::string letters = Constants::uppercaseEnglishAlphabet;
    auto vec = Random::rnd<int>(0, letters.size()-1, N);
    std::string word, word2;
    for (int i = 0; i < N; i++) {
        word += letters[vec[i]], word2 += letters[vec[(i + K) % N]];
    }
    Generator::case_in << word << " " << word2;


    return 0;
}