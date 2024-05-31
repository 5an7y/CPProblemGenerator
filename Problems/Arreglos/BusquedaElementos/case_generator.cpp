#include <iostream>
#include "Generator.hpp"
#include "Random.hpp"
#include <set>

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
    auto queries = Random::rnd(1, 100, K);
    std::set<int> ans;
    for (auto& it : vec) {
        Generator::case_in << it << ' ';
        ans.insert(it);
    }
    Generator::case_in << '\n' << K << '\n';
    for (auto& it : queries) {
        Generator::case_in << it << '\n';
        if (ans.find(it) != ans.end()) 
            Generator::case_out << "S\n";
        else 
            Generator::case_out << "N\n";
    }

    return 0;
}