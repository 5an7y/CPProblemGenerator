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
    std::vector<int64_t> weights;
    std::vector<std::pair<int64_t, int64_t>> people;
    Generator::arguments >> N >> M >> type;
    int64_t D = Random::rnd<int64_t>(1, 1e9 - 1);

    if (type.size() <= 4) {
        weights = Random::rnd<int64_t>(1, 1e9, M);
    } else {
        weights.resize(M, 1);
        type = type.substr(5, type.size() - 5);
    }
    std::sort(weights.begin(), weights.end());

    if (type == "NONE") {
        people.resize(N);
        D++;
        for (auto&[a, f] : people) {
            a = Random::rnd<int64_t>(1, std::min(D * weights[0] - 1, (int64_t)1e9));
            f = Random::rnd<int64_t>(1, std::min((D * weights[0] + (a - 1)) / a - 1, (int64_t)1e9));
        }
    } else if (type == "ALL") {
        people.resize(N);
        for (auto&[a, f] : people) {
            a = Random::rnd<int64_t>(1, 1e9);
            while (1e9 * a < D * weights[M-1]) a *= 2; 
            f = Random::rnd<int64_t>( (D * weights[M-1] + (a - 1)) / a, 1e9);
        }
    } else {
        people = Random::rnd_pair<int64_t>(1, 1e9, N);
    }
    std::random_shuffle(weights.begin(), weights.end());

    Generator::case_in << N << ' ' << M << ' ' << D << '\n';
    for (auto&[a, f] : people) Generator::case_in << a << ' ' << f << '\n';
    for (auto& wi : weights) Generator::case_in << wi << '\n';

    return 0;
}