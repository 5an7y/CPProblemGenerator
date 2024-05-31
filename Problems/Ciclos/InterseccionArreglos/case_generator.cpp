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
    int N, M, K;
    Generator::arguments >> type >> N >> M >> K;
    std::vector<int> A, B;
    if (type == "NOINTER") {
        auto vec = Random::rnd_unique(1, K, N + M);
        auto idxs = Random::rnd_unique(0, N + M-1, N);
        std::sort(vec.begin(), vec.end());
        std::sort(idxs.begin(), idxs.end());
        for (auto& idx : idxs) {
            A.push_back(vec[idx]);
            vec[idx] = -1;
        }
        for (auto& el : vec) {
            if (el > 0) {
                B.push_back(el);
            }
        }
    } else {
        A = Random::rnd(1, K, N);
        B = Random::rnd(1, K, M);
        std::sort(A.begin(), A.end());
        std::sort(B.begin(), B.end());
    }

    Generator::case_in << N << '\n';
    for (auto& it : A) Generator::case_in << it << ' ';
    Generator::case_in << '\n' << M << '\n';
    for (auto& it : B) Generator::case_in << it << ' ';

    return 0;
}