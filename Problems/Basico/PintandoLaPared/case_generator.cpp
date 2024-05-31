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
    int maxn; std::string output, case_type;
    Generator::arguments >> output >> maxn >> case_type;


    int N, M, K;
    std::vector<int> vec;
    if (case_type == "NORMAL" || case_type == "DIVISOR") {
        N = Random::rnd(1, maxn);
        if (case_type == "DIVISOR") {
            std::vector<int> divisores;
            for (int i = 1; i <= sqrt(N); i++)
                if (N % i == 0)  {
                    divisores.push_back(i);
                    divisores.push_back(N/i);
                }
            int aux_sz = Random::rnd<int>(0, divisores.size() - 1);
            K = divisores[aux_sz];
        } else {
            K = Random::rnd(1, (int)sqrt(N));
            if (Random::rnd(0, 1) && K < sqrt(N)) K = Random::rnd(N / (K + 1), N / K);
        }
        
        M = Random::rnd(1, std::min((int)1e5, N));
        vec = Random::rnd_nums_that_sum(N, M);

        int techo = N / K + 1;
        int igual, mayor;
        igual = mayor = 0;

        for (auto& x : vec) {
            if (x == techo) igual++;
            if (x > techo) mayor++;
        }

        if (output == "SI" && !(mayor == 0 && igual <= N % K)) {
            int restante = 0;
            for (auto& x : vec) {
                if (x > techo) restante += x - (techo - 1),x = techo - 1;
                if (x == techo && igual > N % K) igual--, x--, restante++;
            }
            while (restante) {
                vec.push_back(std::min(techo - 1, restante));
                restante -= std::min(techo - 1, restante);
                M++;
            }
        } else if (output == "NO" && (mayor == 0 && igual <= N % K)) {
            vec.push_back(techo + 1); M++;
        }
    } else if (case_type == "ALLONES") {
        K = M = N = Random::rnd(1, maxn);
        vec.resize(M);
        for (auto& it : vec) it = 1;
    } else if (case_type == "LOW") {
        N = Random::rnd(1, maxn);
        K = Random::rnd(1, (int)sqrt(N));
        
        M = Random::rnd(1, std::min((int)1e5, N));
        vec = Random::rnd_nums_that_sum(N, M);

        int techo = N / K + 1;
        int igual, mayor;
        igual = mayor = 0;

        int restante = 0;
        for (auto& x : vec) {
            if (x >= techo) {
                x = techo - 1;
                restante += x - (techo - 1);
            }
        }
        while (restante) {
            vec.push_back(std::min(techo - 1, restante));
            restante -= std::min(techo - 1, restante);
            M++;
        }
    } else {
        N = maxn;
        M = K = Random::rnd(1, (int)sqrt(N));
        vec.resize(M);
        for (int i = 0; i < K; i++) {
            if (i < N % K) vec[i] = N / K + 1;
            else vec[i] = N / K;
        }
        if (output == "NO")
            vec[K-1]++;
    }

    Generator::case_in << N << " " << M << " " << K << '\n';
    for (auto& it : vec) Generator::case_in << it << ' ';

    Generator::case_out << output;

    return 0;
}