#pragma once

#include <vector>
#include <random>
#include "Background.hpp"

namespace Random {
    template <typename T>
    T rnd(T a, T b) {
        std::random_device rd; 
        std::mt19937 gen(rd());
        std::uniform_int_distribution<T> distrib(a, b);
        return distrib(gen);
    }

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

    template <typename T>
    std::vector<T> rnd_unique(T a, T b, std::size_t sz) {
        std::vector<T> vec(sz);
        Background::ST_checker st(a, b);
        uint64_t K = b - a + 1;

        for (int i = 0; i < sz; i++, K--) {
            auto k = rnd<uint64_t>(1, K);
            vec[i] = st.pop_k(k);
        }
        
        return vec;
    }

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
}