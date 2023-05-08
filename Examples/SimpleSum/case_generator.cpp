#include <iostream>
#include "Generator.hpp"
#include "Random.hpp"

int64_t l, r, a, b;

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    

    Generator::arguments >> l >> r;
    a = Random::rnd(l, r);
    b = Random::rnd(l, r);

    Generator::case_in << a << " " << b;
    Generator::case_out << a + b;

    return 0;
}