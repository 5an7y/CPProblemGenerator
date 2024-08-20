#include <iostream>
#include <vector>

#include "Generator.hpp"
#include "Random.hpp"

std::vector<int> primes;
std::vector<bool> shieve;

void build_primes(int maxn) {
    maxn++;
    shieve.resize(maxn, false);
    for (int64_t i = 2; i < maxn; i++) {
        if (shieve[i]) continue;

        primes.push_back(i);
        for (int64_t j = i*i; j < maxn; j+=i) {
            shieve[j] = true;
        }
    }
    std::cerr << maxn << ' ' << primes.size() << '\n';

    return;
}

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
        Use Generator::case_in<< to put elements in case input.
        Use Generator::case_out<< to put elements in case output.
        Use Generator::arguments>> to read the arguments.
    */
    int N, M;
    Generator::arguments >> N >> M;
    std::vector<int> nums;
    if (N == -1) {
        build_primes(M);
        std::random_shuffle(primes.begin(), primes.end());
        for (int i = 10; i < std::min<int>(primes.size(), 100000); i++)
            nums.push_back(primes[i]);
    } else {
        nums = Random::rnd(1, M, N);
    }

    Generator::case_in << nums.size() << '\n';
    for (auto& it : nums) Generator::case_in << it << ' ';

    return 0;
}