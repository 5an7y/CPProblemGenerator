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
    int maxn, maxai;
    Generator::arguments >> maxn >> maxai;
    int N = Random::rnd(1, maxn);
    auto entradas = Random::rnd(1, maxai - 1, N);
    Generator::case_in << N << '\n';
    for (auto& it : entradas) {
        int salida = Random::rnd(it + 1, maxai);
        Generator::case_in << it << ' ' << salida << '\n';
    }

    return 0;
}