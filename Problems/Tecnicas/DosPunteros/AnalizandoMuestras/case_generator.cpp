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
    std::string type;
    Generator::arguments >> N >> M >> type;
    std::vector<std::vector<int>> edges(N);
    if (type == "FULL") {
        for (auto& vi : edges)
            for (int i = 0; i < N; i++)
                vi.push_back(i);
    } else if (type == "RAND") {
        auto szs = Random::rnd_nums_that_sum(M, N);
        for (auto& sz : szs) sz = std::min(sz, N);
        for (int i = 0; i < N; i++)
            edges[i] = Random::rnd_unique(0, N-1, szs[i]);
    } else if (type == "ON_LINE") {
        for (int i = 0; i < N; i++) edges[i] = {i};
    } else if (type == "OFF_LINE") {
        auto szs = Random::rnd_nums_that_sum(M, N);
        for (auto& sz : szs) sz = std::min(sz, N-1);
        for (int i = 0; i < N; i++) {
            edges[i] = Random::rnd_unique(1, N-1, szs[i]);
            for (auto& xi : edges[i]) xi = (i + xi) % N;
        }
    } else if (type == "MOV") {
        int mov1, mov2; Generator::arguments >> mov1 >> mov2;
        auto szs = Random::rnd_nums_that_sum(M, N);

        int l1 = mov1, l2 = N - mov2, K = l2 - l1 - 1;
        for (auto& sz : szs) sz = std::min(sz, 1 + K);
        for (int i = 0; i < N; i++) {
            edges[i] = Random::rnd_unique(l1 + 1, l2 - 1, szs[i]-1);
            for (auto& xi : edges[i]) xi = (i + xi) % N;
            edges[i].push_back((i + Random::rnd(-mov2, mov1) + N) % N);
        }
    } else if (type == "SAME_POS") {
        int d = Random::rnd(0, N-1);
        for (int i = 0; i < N; i++) edges[i] = {d};
    } else if (type == "RIGHT") {
        int mov; Generator::arguments >> mov;
        auto szs = Random::rnd_nums_that_sum(M, N);
        for (int i = 0; i < N; i++) {
            szs[i] = std::min({szs[i], mov + 1, N - i});
            auto aux = Random::rnd(0, std::min(mov, N - i - 1), szs[i]);
            edges[i].resize(szs[i]);
            for (int j = 0; j < szs[i]; j++) 
                edges[i][j] = i + aux[j];
        }
    }

    Generator::case_in << N << '\n';
    for(auto& ed : edges) {
        Generator::case_in << ed.size() << ' ';
        for (auto& xi : ed) Generator::case_in << xi << ' ';
        Generator::case_in << '\n';
    }
    return 0;
}