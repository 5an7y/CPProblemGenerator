#include <iostream>
#include <algorithm>
#include "Generator.hpp"
#include "Random.hpp"

int N;

void generate_normal() {
    auto characters = Random::rnd(1, 4, N);
    std::vector<int> vals(N);
    characters[0] = 2;
    int dragones_act = 0;

    for (int i = 0; i < N; i++) {
        if (characters[i] == 1) {
            Generator::case_in << "M ";
            vals[i] = Random::rnd(1, dragones_act + 4);
            dragones_act = std::min(vals[i], dragones_act);
        } else {
            Generator::case_in << "D ";
            dragones_act++;
            vals[i] = Random::rnd(1, 1000000);
        }
    } 

    Generator::case_in << "\n";
    for (auto& it: vals)
        Generator::case_in << it << " ";
    
    return;
}

void generate_no_goblins() {
    auto vals = Random::rnd(1, 1000000, N);

    for (int i = 0; i < N; i++)
        Generator::case_in << "D ";

    Generator::case_in << "\n";
    for (auto& it: vals)
        Generator::case_in << it << " ";
    
    return;
}

void generate_increasing() {
    auto characters = Random::rnd(1, 4, N);
    auto vals = Random::rnd_unique(1, 1000000, N);
    std::sort(vals.begin(), vals.end());
    for (int i = 0; i < N; i++) {
        if (characters[i] == 1) {
            Generator::case_in << "M ";
        } else {
            Generator::case_in << "D ";
        }
    }
    Generator::case_in << "\n";
    for (auto& it: vals)
        Generator::case_in << it << " ";
    return;
}

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
        Use Generator::case_in<< to put elements in case input.
        Use Generator::case_out<< to put elements in case output.
        Use Generator::arguments>> to read the arguments.
    */
   std::string caso;
   Generator::arguments >> N >> caso;
   Generator::case_in << N << '\n';
   if (caso == "NG") generate_no_goblins();
   if (caso == "IN") generate_increasing();
   if (caso == "NO") generate_normal();

    return 0;
}