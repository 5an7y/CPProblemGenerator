#include <iostream>
#include <unordered_set>
#include "Generator.hpp"
#include "Random.hpp"

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
        Use Generator::case_in<< to put elements in case input.
        Use Generator::case_out<< to put elements in case output.
        Use Generator::arguments>> to read the arguments.
    */
    int N, X, POS; std::string case_type;
    Generator::arguments >> N >> case_type;
    POS = Random::rnd(0, N-1);

    std::unordered_set<int> menores, mayores;
    int left = 0, right = N;
    while (left < right) {
        int middle = (left + right) / 2;
        if (POS > middle) menores.insert(middle), left = middle + 1;
        else if (POS < middle) mayores.insert(middle), right = middle;
        else left = middle + 1;
    }

    if (case_type == "EQUAL") X = POS + 1;
    else if (case_type == "POSSIBLE") X = Random::rnd(menores.size() + 1, N - mayores.size());
    else if (Random::rnd(0, 1)) X = Random::rnd<int>(1, menores.size());
    else X = Random::rnd<int>(N - mayores.size() + 1, N);

    Generator::case_in << N << " " << X << " " << POS;

    return 0;
}