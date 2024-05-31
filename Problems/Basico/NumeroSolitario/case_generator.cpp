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
    auto vec = Random::rnd_unique(1, 100, N);
    Generator::case_out << vec[N - 1];
    for (int i = 0; i < N - 1; i++)
        vec.push_back(vec[i]);
    std::random_shuffle(vec.begin(), vec.end());
    Generator::case_in << vec.size() << '\n';
    for (auto& it : vec) Generator::case_in << it << ' ';

    return 0;
}