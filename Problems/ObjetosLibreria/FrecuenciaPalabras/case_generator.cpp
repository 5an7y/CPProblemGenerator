#include <iostream>
#include <algorithm>
#include <map>

#include "Generator.hpp"
#include "Random.hpp"
#include "Constants.hpp"

const std::string strGenerator = Constants::lowercaseEnglishAlphabet + Constants::uppercaseEnglishAlphabet;
const std::string generate_random_string(int sz) {
    auto indexes = Random::rnd<int>(0, strGenerator.size(), sz);
    std::string ans;
    for (auto& idx : indexes) ans += strGenerator[idx];
    return ans;
}

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
    Use Generator::case_in<< to put elements in case input.
    Use Generator::case_out<< to put elements in case output.
    Use Generator::arguments>> to read the arguments.
    */
    int sz, dif;
    Generator::arguments >> sz >> dif;
    Generator::case_in << sz << '\n';

    auto vec = Random::rnd_nums_that_sum(sz, dif);
    std::vector<std::string> words;
    std::map<std::string, int> mapeo;
    int maxi = 0;

    for (auto& it: vec) {
        const int strSz = Random::rnd(8, 30);
        const std::string randomStr = generate_random_string(strSz);
        mapeo[randomStr] += it;
        maxi = std::max(maxi, mapeo[randomStr]);

        for (int i = 0; i < it; i++)
            words.push_back(randomStr);
    }

    std::random_shuffle(words.begin(), words.end());
    for (auto& word: words)
        Generator::case_in << word << '\n';

    for (auto& [key, value] : mapeo)
        if (value == maxi) {
            Generator::case_out << key << '\n';
            return 0;
        }

    return 0;
}