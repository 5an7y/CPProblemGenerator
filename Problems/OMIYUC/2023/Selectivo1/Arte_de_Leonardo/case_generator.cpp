#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include "Generator.hpp"
#include "Random.hpp"

std::vector<int> resolve(int N, std::vector<std::tuple<int, int, int>>& ranges) {
    std::vector<std::vector<std::tuple<int, int, int>>> vec(N);
    std::vector<int> ans(N);
    std::reverse(ranges.begin(), ranges.end());

    int K = ranges.size();
    for (auto& [l, r, c] : ranges) {
        vec[l].push_back({K, r, c});
        K--;
    }

    std::priority_queue<std::tuple<int, int, int>> pq;

    for (int i = 0; i < N; i++) {
        for (auto& [t, r, c] : vec[i])
            pq.push({t, r, c});
        
        while (!pq.empty()) {
            auto [t, r, c] = pq.top();
            if (i <= r) {
                ans[i] = c;
                break;
            }
            pq.pop();
        }
    }

    return ans;
}

void create_random_good(uint32_t l, uint32_t r) {
    auto N = Random::rnd(l, r);
    auto K = Random::rnd((uint32_t)1, N);
    auto ranges = Random::rnd_pair((uint32_t)0, N-1, K);
    auto colors = Random::rnd_unique((uint32_t)1, N, K);
    std::vector<std::tuple<int, int, int>> queries(K);

    for (int i = 0; i < K; i++) {
        uint32_t k_min = Random::rnd(10, 100);
        queries[i] = {ranges[i].first, std::min(ranges[i].second, ranges[i].first + k_min), colors[i]};
    }

    auto vecin = resolve(N, queries);

    Generator::case_in << N << '\n';
    for (int i = 0; i < N; i++)
        Generator::case_in << vecin[i] << " \n"[i == N-1];
    return;
}

void create_almost(uint32_t l, uint32_t r) {
    auto N = Random::rnd(l, r);
    auto K = Random::rnd((uint32_t)1, N-2);
    auto ranges = Random::rnd_pair((uint32_t)0, N-1, K);
    auto colors = Random::rnd_unique((uint32_t)1, N, K+2);
    std::vector<std::tuple<int, int, int>> queries(K);
    
    for (int i = 0; i < K; i++)
        queries[i] = {ranges[i].first, ranges[i].second, colors[i]};
    
    auto vecin = resolve(N, queries);

    auto l1 = Random::rnd<uint32_t>(0, N - 4);
    auto r1 = Random::rnd<uint32_t>(l1 + 2, N - 2);
    auto l2 = Random::rnd<uint32_t>(l1+1, r1-1);
    auto r2 = Random::rnd<uint32_t>(r1 + 1, N-1);
    vecin[l1] = vecin[r1] = colors[K];
    vecin[l2] = vecin[r2] = colors[K + 1];

    Generator::case_in << N << '\n';
    for (int i = 0; i < N; i++)
        Generator::case_in << vecin[i] << " \n"[i == N-1];

    return;
}

void create_piramid(uint32_t l, uint32_t r) {
    auto N = Random::rnd(l, r);
    uint32_t l1 = 0, r1 = N-1;
    std::vector<std::pair<uint32_t, uint32_t>> ranges;
    while (l1 <= r1) {
        ranges.push_back({l1, r1});
        l1++, r1--;
    }
    uint32_t K = ranges.size();
    auto colors = Random::rnd_unique((uint32_t)1, N, K);
    std::vector<std::tuple<int, int, int>> queries(K);

    for (int i = 0; i < K; i++)
        queries[i] = {ranges[i].first, ranges[i].second, colors[i]};
    
    auto vecin = resolve(N, queries);

    Generator::case_in << N << '\n';
    for (int i = 0; i < N; i++)
        Generator::case_in << vecin[i] << " \n"[i == N-1];

    return;
}

void generate_cases(int l, int r, std::vector<std::pair<uint32_t, uint32_t>>& ranges) {
    if (r < l) return;
    ranges.push_back({l, r});
    int mit = (l + r) / 2;
    generate_cases(l + 1, mit - 1, ranges);
    generate_cases(mit + 1, r - 1, ranges);
    return;
}

void create_binary(uint32_t l, uint32_t r) {
    auto N = Random::rnd(l, r);
    std::vector<std::pair<uint32_t, uint32_t>> ranges;
    generate_cases(0, N - 1, ranges);

    uint32_t K = ranges.size();
    auto colors = Random::rnd_unique((uint32_t)1, N, K);
    std::vector<std::tuple<int, int, int>> queries(K);

    for (int i = 0; i < K; i++)
        queries[i] = {ranges[i].first, ranges[i].second, colors[i]};
    
    auto vecin = resolve(N, queries);

    Generator::case_in << N << '\n';
    for (int i = 0; i < N; i++)
        Generator::case_in << vecin[i] << " \n"[i == N-1];

    return;
}

void create_all_diferent(uint32_t l, uint32_t r) {
    auto N = Random::rnd(l, r);
    auto vecin = Random::rnd_unique((uint32_t)1, N, N);

    Generator::case_in << N << '\n';
    for (int i = 0; i < N; i++)
        Generator::case_in << vecin[i] << " \n"[i == N-1];
    return;
}

void create_all_zero(uint32_t l, uint32_t r) {
    auto N = Random::rnd(l, r);
    std::vector<int> vecin(N, 0);

    Generator::case_in << N << '\n';
    for (int i = 0; i < N; i++)
        Generator::case_in << vecin[i] << " \n"[i == N-1];

    return;
}

void create_some_zeros(uint32_t l, uint32_t r) {
    auto N = Random::rnd(l, r);
    uint32_t spacing = (N < 10000) ? N / 10 : Random::rnd(10, 100);
    uint32_t li = 0, ri = spacing;
    std::vector<std::pair<int, int>> ranges;
    
    while (ri < N) {
        int n = ri - li + 1 - 2;
        int k = Random::rnd(1, n);
        auto n_queries = Random::rnd_pair(li + 1, ri - 1, k);
        for (auto& a: n_queries)
            ranges.push_back(a);
        
        li = ri;
        ri = std::min(ri + spacing, N);
    }
    
    uint32_t K = ranges.size();
    auto colors = Random::rnd_unique((uint32_t)1, N, K);
    std::vector<std::tuple<int, int, int>> queries(K);

    for (int i = 0; i < K; i++)
        queries[i] = {ranges[i].first, ranges[i].second, colors[i]};

    auto vecin = resolve(N, queries);

    Generator::case_in << N << '\n';
    for (int i = 0; i < N; i++)
        Generator::case_in << vecin[i] << " \n"[i == N-1];
    return;
}

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
        Use Generator::case_in<< to put elements in case input.
        Use Generator::case_out<< to put elements in case output.
        Use Generator::arguments>> to read the arguments.
    */
    std::string S;
    uint32_t l, r;

    Generator::arguments >> S >> l >> r;

    if (S == "RandomGood") {
        create_random_good(l, r);
    } else if (S == "Almost") {
        create_almost(l, r);
    } else if (S == "Piramid") {
        create_piramid(l, r);
    } else if (S == "Binary") {
        create_binary(l, r);
    } else if (S == "AllDiferent") {
        create_all_diferent(l, r);
    } else if (S == "AllZero") {
        create_all_zero(l, r);
    } else if (S == "SomeZeros") {
        create_some_zeros(l, r);
    }

    return 0;
}   