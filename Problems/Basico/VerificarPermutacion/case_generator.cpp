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
    std::string type;
    Generator::arguments >> type >> N;
    std::vector<int> vec;
    if (type == "RAND") {
        vec = Random::rnd(1, 100, N);
    } else if (type == "PER") {
        for (int i = 1; i <= N; i++) vec.push_back(i);
        std::random_shuffle(vec.begin(), vec.end());
    } else if (type == "REP") {
        for (int i = 1; i <= N; i++) vec.push_back(i);
        std::random_shuffle(vec.begin(), vec.end());
        vec[N-1] = vec[0];
        std::random_shuffle(vec.begin(), vec.end());
    } else if (type == "SUMEQ") {
        for (int i = 1; i <= N; i++) vec.push_back(i);
        std::random_shuffle(vec.begin(), vec.end());
        vec[0]--;
        vec[1]++;
        vec[2]--;
        vec[3]++;
        std::random_shuffle(vec.begin(), vec.end());
    } else if (type == "MAX") {
        for (int i = 1; i <= N; i++) vec.push_back(i);
        vec[N-1] = N+1;
        std::random_shuffle(vec.begin(), vec.end());
    }

    Generator::case_in << N << '\n';
    for (auto& it : vec) Generator::case_in << it << ' ';

    return 0;
}