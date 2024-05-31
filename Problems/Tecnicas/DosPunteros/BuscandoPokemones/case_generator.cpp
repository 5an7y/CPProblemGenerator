#include <iostream>
#include "Generator.hpp"
#include "Random.hpp"

std::string usableLetters;

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
        Use Generator::case_in<< to put elements in case input.
        Use Generator::case_out<< to put elements in case output.
        Use Generator::arguments>> to read the arguments.
    */
    for (char a = 'a'; a <= 'z'; a++)
        usableLetters += a;
    for (char a = 'A'; a <= 'Z'; a++)
        usableLetters += a;
    
    int N; std::string type;
    Generator::arguments >> N >> type;
    if (type == "AllSame") {
        Generator::case_in << N << '\n';
        for (int i = 0; i < N; i++)
            Generator::case_in << 'h';
    } else if (type == "Repeat") {
        Generator::case_in << N * usableLetters.size() << '\n';
        for (int i = 0; i < N; i++) {
            Generator::case_in << usableLetters;
        }
    } else if (type == "Initial") {
        Generator::case_in << N << '\n';
        for (int i = 0; i < N-usableLetters.size(); i++) {
            Generator::case_in << 'a';
        }
        Generator::case_in << usableLetters;
    } else if (type == "Final") {
        Generator::case_in << N << '\n';
        Generator::case_in << usableLetters;
        for (int i = 0; i < N-usableLetters.size(); i++) {
            Generator::case_in << 'Z';
        }
    } else {
        Generator::case_in << N << '\n';
        int K = Random::rnd<int>(1, usableLetters.size());
        auto vec = Random::rnd_unique<int>(0, usableLetters.size()-1, K);
        std::string letters;
        for (auto& xi : vec) letters += usableLetters[xi];
        std::cout << K << " " << letters << '\n';
        auto vec2 = Random::rnd(0, K-1, N);
        for (auto& xi : vec2) Generator::case_in << letters[xi];
    }

    return 0;
}