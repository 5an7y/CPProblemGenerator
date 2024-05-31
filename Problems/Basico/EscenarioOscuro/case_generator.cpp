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
    int N, M, K;
    N = Random::rnd(1, 100);
    M = Random::rnd(1, 100);
    K = Random::rnd(1, 100);

    std::string type;
    Generator::arguments >> type;

    if (type == "All") {
        Generator::case_in << N << ' ' << M << ' ' << K << '\n';
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) Generator::case_in << '*';
            Generator::case_in << ' ';
            for(int j = 0; j < K; j++) Generator::case_in << "*-"[Random::rnd(0, 1)];
            Generator::case_in << '\n';
        }
        Generator::case_out << 'S';
    } else if (type == "NoPattern") {
        Generator::case_in << N << ' ' << M << ' ' << K << '\n';
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) Generator::case_in << "*-"[Random::rnd(0, 1)];
            Generator::case_in << ' ';
            for(int j = 0; j < K; j++) Generator::case_in << "-";
            Generator::case_in << '\n';
        }
        Generator::case_out << 'S';
    } else if (type == "NoLights") {
        Generator::case_in << N << ' ' << M << ' ' << K << '\n';
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) Generator::case_in << "-";
            Generator::case_in << ' ';
            for(int j = 0; j < K; j++) Generator::case_in << "*-"[Random::rnd(0, 1)];
            Generator::case_in << '\n';
        }
        Generator::case_out << 'N';
    } else if (type == "AlterNo") {
        Generator::case_in << N << ' ' << M << ' ' << K << '\n';
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) Generator::case_in << "*-"[i%2];
            Generator::case_in << ' ';
            for(int j = 0; j < K; j++) Generator::case_in << "*-"[1 - i%2];
            Generator::case_in << '\n';
        }
        Generator::case_out << 'N';
    } else if (type == "AlterYes") {
        Generator::case_in << N << ' ' << M << ' ' << K << '\n';
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) Generator::case_in << "*-"[i%2];
            Generator::case_in << ' ';
            for(int j = 0; j < K; j++) Generator::case_in << "*-"[i%2];
            Generator::case_in << '\n';
        }
        Generator::case_out << 'S';
    } else if (type == "RandNo") {
        Generator::case_in << N << ' ' << M << ' ' << K << '\n';
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) Generator::case_in << "*-"[Random::rnd(0, 1)];
            Generator::case_in << ' ';
            for(int j = 0; j < K; j++) Generator::case_in << "*-"[Random::rnd(0, 1)];
            Generator::case_in << '\n';
        }
        Generator::case_out << 'N';
    } else if (type == "RandYes") {
        Generator::case_in << N << ' ' << M << ' ' << K << '\n';
        for(int i = 0; i < N; i++) {
            bool scn_all_light = Random::rnd(0, 1);
            if (scn_all_light) for(int j = 0; j < M; j++) Generator::case_in << "*";
            else for(int j = 0; j < M; j++) Generator::case_in << "*-"[Random::rnd(0, 1)];
            Generator::case_in << ' ';
            if (!scn_all_light) for(int j = 0; j < K; j++) Generator::case_in << "-";
            else for(int j = 0; j < K; j++) Generator::case_in << "*-"[Random::rnd(0, 1)];
            Generator::case_in << '\n';
        }
        Generator::case_out << 'S';
    } else if (type == "OneYes") {
        Generator::case_in << 1 << ' ' << 1 << ' ' << 1 << '\n';
        Generator::case_in << "- -";
        Generator::case_out << 'S';
    } else {
        Generator::case_in << 1 << ' ' << 1 << ' ' << 1 << '\n';
        Generator::case_in << "- *";
        Generator::case_out << 'N';
    }

    return 0;
}