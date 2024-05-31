#include <iostream>
#include <vector>
#include "Generator.hpp"
#include "Random.hpp"

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
        Use Generator::case_in<< to put elements in case input.
        Use Generator::case_out<< to put elements in case output.
        Use Generator::arguments>> to read the arguments.
    */
    int maxn, maxai; std::string type_case;
    Generator::arguments >> maxn >> maxai >> type_case;

    int N; std::vector<int> nums;
    if (type_case != "NORMAL") N = maxn;
    else N = Random::rnd(2, maxn);

    if (type_case == "DECREASING") {
        nums.resize(N);
        for (int i = 0; i < N; i++) nums[i] = std::max(N - i, 1);
    } else if (type_case == "MAX") {
        nums.resize(N);
        for(auto& it : nums) it = maxai;
    } else {
        nums = Random::rnd(1, maxai, N);
    }

    Generator::case_in << N << '\n';
    for(auto& it : nums) Generator::case_in << it << ' ';

    return 0;
}