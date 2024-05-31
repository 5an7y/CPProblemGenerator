#pragma once

#include <vector>
#include <algorithm>
#include <random>
#include "Background.hpp"

namespace Random {

    // Generates a random number between [a, b]. (inclusive)
    template <typename T>
    T rnd(T a, T b) {
        std::random_device rd; 
        std::mt19937 gen(rd());
        std::uniform_int_distribution<T> distrib(a, b);
        return distrib(gen);
    }

    // Generates a random vector filled with numbers between [a, b].
    template <typename T>
    std::vector<T> rnd(T a, T b, std::size_t sz) {
        std::random_device rd; 
        std::mt19937 gen(rd());
        std::uniform_int_distribution<T> distrib(a, b);

        std::vector<T> vec(sz);
        for (auto& el : vec)
            el = distrib(gen);
        return vec;
    }

    // Generates a random vector filled with UNIQUE numbers between [a, b].
    template <typename T>
    std::vector<T> rnd_unique(T a, T b, std::size_t sz) {
        std::vector<T> vec(sz);
        if (a > b) {
            throw std::invalid_argument("In rnd_unique(a, b) a should be less or equal than b.");
        }
        uint64_t K = b - a + 1;
        Background::ST_checker<uint64_t> st(0, K-1);

        for (int i = 0; i < sz; i++, K--) {
            auto k = rnd<uint64_t>(1, K);
            vec[i] = st.pop_k(k) + a;
        }
        
        return vec;
    }

    // Generates a random pair of numbers between [a, b].
    template <typename T>
    std::pair<T, T> rnd_pair(T a, T b) {
        std::random_device rd; 
        std::mt19937 gen(rd());
        std::uniform_int_distribution<T> distrib(a, b);
        T a1, a2;
        a1 = distrib(gen);
        a2 = distrib(gen);
        if (a1 > a2) std::swap(a1, a2);
        return {a1, a2};
    }

    // Generates a vector filled with random pair of numbers between [a, b].
    template <typename T>
    std::vector<std::pair<T, T>> rnd_pair(T a, T b, std::size_t sz) {
        std::random_device rd; 
        std::mt19937 gen(rd());
        std::uniform_int_distribution<T> distrib(a, b);
        std::vector<std::pair<T, T>> vec(sz);

        for (auto& [a1, a2] : vec) {
            a1 = distrib(gen);
            a2 = distrib(gen);
            if (a1 > a2) std::swap(a1, a2);
        }
        return vec;
    }

    // Generates a vector with random numbers, such that the sum of all numbers equals SUM. If allow_zero flag is enable, zeros are allowed.
    template <typename T>
    std::vector<T> rnd_nums_that_sum(T sum, std::size_t sz, bool allow_zero = false) {
        std::vector<T> uniqueRandom;
        if (allow_zero) uniqueRandom = rnd(0, sum, sz);
        else uniqueRandom = rnd_unique(0, sum-1, sz);
        
        std::sort(uniqueRandom.begin(), uniqueRandom.end());
        uniqueRandom.push_back(sum);
        std::vector<T> vec(sz);
        for (int i = 1; i <= sz; i++)
            vec[i - 1] = uniqueRandom[i] - uniqueRandom[i - 1];
        
        return vec;
    }

    // Generates a random tree, the return vector are the edges of the tree.
    std::vector<std::pair<int, int>> rnd_tree(int N) {
        if(N == 1) return {};

        auto parents = rnd(1, N-1, N);
        std::vector<std::pair<int, int>> vec(N);
        for (int i = 0; i < N; i++) {
            parents[i] = (parents[i] + i) % N;
            vec[i] = ( 
                rnd(0, 1) ? std::make_pair(i, parents[i]) : std::make_pair(parents[i], i)
            );
        }
        std::random_shuffle(vec.begin(), vec.end());
        vec.pop_back();
        
        return vec;
    }

    // Generates a random forest, the return vector are the edges of the forest. N is the numbers of nodes and trees the number of trees in the forest.
    std::vector<std::pair<int, int>> rnd_forest(int N, int trees) {
        if (N > trees) {
            throw std::invalid_argument("The number of nodes should be at least equal to the number of forest.");
        }
        auto tree_szs = rnd_nums_that_sum(N, trees);
        auto permutation = rnd_unique(0, N-1, N);
        std::vector<std::pair<int, int>> edges;
        int shifted = 0;

        for (int i = 0; i < trees; i++) { 
            int sz = tree_szs[i];
            auto subtree = rnd_tree(sz);
            for (auto [a, b] : subtree) edges.push_back({permutation[a + shifted], permutation[b + shifted]});
            shifted += sz;
        }
        
        return edges;
    }
}