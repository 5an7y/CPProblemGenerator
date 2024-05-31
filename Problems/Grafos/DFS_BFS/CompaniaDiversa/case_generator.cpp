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
    int N, M; std::string case_type;
    Generator::arguments >> N >> case_type;
    std::vector<std::vector<int>> vec(N);
    if (case_type == "ONELAN") {
        M = 1;
        auto aux = Random::rnd_unique(0, N-1, N);
        int K = Random::rnd(0, N);
        for (int i = 0; i < K; i++)
            vec[aux[i]].push_back(1);
    } else if (case_type == "ONELEARN") {
        auto aux = Random::rnd_unique(0, N-1, N);
        M = Random::rnd(1, N);
        auto component_sizes = Random::rnd_nums_that_sum(N, M);
        for (int i = 0, sz_idx = 0; sz_idx < M; sz_idx++) {
            int cmp_sz = component_sizes[sz_idx];
            for (int j = i; j < i + cmp_sz; j++)
                vec[aux[j]].push_back(sz_idx + 1);
            i += cmp_sz;
        }
    } else if (case_type == "NORMAL") {
        auto aux = Random::rnd_unique(0, N-1, N);
        M = Random::rnd(1, N);
        auto component_sizes = Random::rnd_nums_that_sum(N, M);
        for (int i = 0, sz_idx = 0; sz_idx < M; sz_idx++) {
            int cmp_sz = component_sizes[sz_idx];
            int tgt = i + cmp_sz, st = i;
            if (cmp_sz == 1) {
                i++;
                continue;
            }
            while (i < tgt) {
                int K = Random::rnd(2, cmp_sz);
                for (int j = 0, act = i; j < K; act++, j++) {
                    if (act == tgt) act = st;
                    vec[aux[act]].push_back(i + 1);
                }
                i++;
            }
        }
        M = N;
    } else if (case_type == "ALLDISTINC") {
        M = Random::rnd(N + 1, 1000);
        auto aux = Random::rnd_nums_that_sum(M, N);
        for (int i = 0, lan = 1; i < N; i++) {
            vec[i].resize(aux[i]);
            for (int j = 0; j < aux[i]; j++)
                vec[i][j] = lan++;
        } 
    } else if (case_type == "SUBSECUENTE") {
        M = N - 1;
        for (int i = 0; i < N - 1; i++) {
            vec[i].push_back(i + 1);
            vec[i+1].push_back(i + 1);
        }
    } else if (case_type == "ALLCONECTED") {
        auto aux = Random::rnd_unique(0, N-1, N);
        for (int i = 0; i < N; i++) {
            int K = Random::rnd(2, N);
            for (int j = 0, act = i; j < K; act++, j++) {
                if (act == N) act = 0;
                vec[aux[act]].push_back(i + 1);
            }
            i++;
        }
        M = N;
    }

    Generator::case_in << N << ' ' << M << '\n';
    for (auto& persona : vec) {
        Generator::case_in << persona.size() << ' ';
        for (auto& it : persona) Generator::case_in << it << ' ';
        Generator::case_in << '\n';
    }

    return 0;
}