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
    int N, M;
    Generator::arguments >> N >> M;
    Generator::case_in << N << " " << M << '\n';
    std::vector<std::vector<int>> mat(N);
    for (auto& vec : mat) { 
        vec = Random::rnd(1, 100, M);
        for(auto& it : vec) {
            Generator::case_in << it << ' ';
        }
        Generator::case_in << '\n';
    }
    std::vector<std::vector<int>> mat2(M, std::vector<int>(N));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            mat2[i][j] = mat[j][M-1-i];
        }
    }

    for (auto& vec : mat2) {
        for(auto& it : vec) {
            Generator::case_out << it << ' ';
        }
        Generator::case_out << '\n';
    }

    return 0;
}