#include <iostream>
#include "Generator.hpp"

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
        Use Generator::case_in<< to put elements in case input.
        Use Generator::case_out<< to put elements in case output.
        Use Generator::arguments>> to read the arguments.
    */
    int N;
    int fib[25];
    fib[0] = 0;
    fib[1] = 1;
    Generator::arguments >> N;
    Generator::case_in << N << '\n';

    for (int i = 2; i < N; i++)
        fib[i] = fib[i-1] + fib[i - 2]; 

    Generator::case_out << fib[N-1] << '\n';    

    return 0;
}