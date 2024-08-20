#include <iostream>
#include "Generator.hpp"
#include "Random.hpp"
#include <exception>

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
        Use Generator::case_in<< to put elements in case input.
        Use Generator::case_out<< to put elements in case output.
        Use Generator::arguments>> to read the arguments.
    */
    int N;
    std::string typ;
    Generator::arguments >> N >> typ;
    std::vector<std::pair<int, int>> parejas(N);

    if (typ == "NO_OVERLAP") {
        int suma = Random::rnd<int>(2 * N, 1e6);
        auto aux = Random::rnd_nums_that_sum<int>(1e6, 2 * N);
        int s = 0;
        for (int i = 0; i < N; i++) {
            s += aux[2*i];
            parejas[i] = {s, s + aux[2 * i + 1]};
            s += aux[2 * i + 1];
        }
        std::random_shuffle(parejas.begin(), parejas.end());

    } else if (typ == "SAME") {
        int l = Random::rnd<int>(1, 1e6-1);
        int r = Random::rnd<int>(1, 1e6);
        if (l > r) std::swap(l, r);
        if (l == r) l++;
        for (auto& [a, b] : parejas) a = l, b = r;
    
    } else if (typ == "CONST_OVERLAP") {
        parejas[0] = Random::rnd_pair<int>(1, 1e6-1);
        if (parejas[0].first > parejas[0].second) std::swap(parejas[0].first, parejas[0].second);
        if (parejas[0].first == parejas[0].second) parejas[0].second++; 

        for (int i = 1; i < N; i++) {
            parejas[i].first = Random::rnd(parejas[i-1].first, parejas[i-1].second); 
            if (parejas[i].first == 1e6) parejas[i].first--;
            parejas[i].second = Random::rnd<int>(parejas[i].first + 1, 1e6);
        }
        std::random_shuffle(parejas.begin(), parejas.end());

    } else if (typ == "SAME_INI") {
        int K = Random::rnd<int>(1, 1e6-1);
        auto aux = Random::rnd<int>(K+1, 1e6, N);
        for (int i = 0; i < N; i++) parejas[i] = {K, aux[i]};

    } else if (typ == "CONT") {
        int suma = Random::rnd<int>(2 * N, 1e6);
        auto inis = Random::rnd_nums_that_sum<int>(suma/2, N, true);
        auto fins = Random::rnd_nums_that_sum<int>(suma/2, N);
        int ant = 0;
        for (int i = 0; i < N; i++) {
            parejas[i] = {ant + inis[i], ant + inis[i] + fins[i]};
            ant += inis[i] + fins[i];
        }
    } else if (typ == "CONST_SIZE") {
        int sz = Random::rnd<int>(1, 1000);
        auto inis = Random::rnd<int>(1, 1e6 - sz, N);
        for (int i = 0; i < N; i++) parejas[i] = {inis[i], inis[i] + sz};
    } else if (typ == "RAND") {
        parejas = Random::rnd_pair<int>(1, 1e6, N);
        for (auto& [a, b] : parejas) { 
            if (a > b) std::swap(a, b);
            if (a == b) {
                if (a > 1) a--; 
                else b++;
            }
        }
    } else {
        throw std::invalid_argument("No " + typ + " implemented");
    }

    Generator::case_in << N << '\n';
    for (auto& [a, b] : parejas) Generator::case_in << a << ' ' << b << '\n';

    return 0;
}