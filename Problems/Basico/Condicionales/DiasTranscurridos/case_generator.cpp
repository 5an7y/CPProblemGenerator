#include <iostream>
#include "Generator.hpp"
#include "Random.hpp"

std::vector<std::string> meses = {
        "ENE", "FEB", "MAR", "ABR", "MAY", "JUN", "JUL", "AGO", "SEP", "OCT", "NOV", "DIC"
    };
std::vector<int> dias = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
        Use Generator::case_in<< to put elements in case input.
        Use Generator::case_out<< to put elements in case output.
        Use Generator::arguments>> to read the arguments.
    */
    std::string case_type;
    Generator::arguments >> case_type;
    int m1, m2, d1, d2;

    if (case_type == "SUB1") {
        m1 = m2 = Random::rnd(0, 11);
        d1 = Random::rnd(1, dias[m1] - 1);
        d2 = Random::rnd(d1 + 1, dias[m2]);
    } else if (case_type == "SUB2") {
        m1 = 6; m2 = 7;
        d1 = Random::rnd(1, dias[m1]);
        d2 = Random::rnd(1, dias[m2]);
    } else if (case_type == "SUB3") {
        m1 = Random::rnd(0, 11);
        m2 = Random::rnd(0, 11);
        if (m2 < m1) std::swap(m1, m2);
        d1 = Random::rnd(1, dias[m1]);
        d2 = Random::rnd(1, dias[m2]);
        if (m1 == m2 && d2 < d1) std::swap(d1, d2);
    } else if (case_type == "EDGE") {
        m1 = 11, m2 = 0, d1 = 31, d2 = 1;
    } else if (case_type == "SAME") {
        m1 = m2 = Random::rnd(0, 11);
        d1 = d2 = Random::rnd(1, dias[m1]);
    } else if (case_type == "MONTH") {
        m1 = m2 = Random::rnd(0, 11);
        d1 = Random::rnd(1, dias[m1]);
        d2 = Random::rnd(1, dias[m2]);
    } else {
        m1 = Random::rnd(0, 11);
        m2 = Random::rnd(0, 11);
        d1 = Random::rnd(1, dias[m1]);
        d2 = Random::rnd(1, dias[m2]);
    }

    Generator::case_in << meses[m1] << ' ' << d1 << '\n'
                       << meses[m2] << ' ' << d2; 

    return 0;
}