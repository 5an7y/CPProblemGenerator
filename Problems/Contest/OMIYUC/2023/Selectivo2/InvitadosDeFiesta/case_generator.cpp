#include <iostream>
#include <algorithm>

#include "Generator.hpp"
#include "Random.hpp"

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
        Use Generator::case_in<< to put elements in case input.
        Use Generator::case_out<< to put elements in case output.
        Use Generator::arguments>> to read the arguments.
    */
    std::string type;
    int N, M, K, UP_LIMIT;
    Generator::arguments >> type >> N >> M >> K >> UP_LIMIT;

    auto santyFriends = Random::rnd_unique(0, UP_LIMIT, N);
    auto blacklistIdx = Random::rnd_unique(0, N-1, M);
    std::vector<int> blacklist(M);
    for (int i = 0; i < M; i++)
        blacklist[i] = santyFriends[blacklistIdx[i]];

    if (type == "SORTED") {
        std::sort(santyFriends.begin(), santyFriends.end());
        std::sort(blacklist.begin(), blacklist.end());
    }

    Generator::case_in << N << " " << M << " " << K << '\n';
    for (auto& it : santyFriends) Generator::case_in << it << ' ';
    Generator::case_in << '\n';
    for (auto& it : blacklist) Generator::case_in << it << ' ';
    Generator::case_in << '\n';

    return 0;
}