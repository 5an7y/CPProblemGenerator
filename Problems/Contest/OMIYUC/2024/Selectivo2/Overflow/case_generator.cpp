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
    int64_t n, a, b;
    Generator::arguments >> n >> a >> b;
    if (abs(a) != 5) {
       ;
    } else if (a == 5) {
        int64_t maxi = ( ((uint64_t)1) << (n-1) ) - 1;
        a = Random::rnd(maxi/2, maxi);
        b = Random::rnd(maxi/2, maxi);
    } else {
        int64_t mini = ( ((uint64_t)1) << (n-1) ) - 1;
        mini = -mini - 1;
        a = Random::rnd(mini, mini/2);
        b = Random::rnd(mini, mini/2);
    }

    Generator::case_in << n << '\n' << a << ' ' << b;

    return 0;
}