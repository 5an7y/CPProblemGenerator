#include <iostream>
#include <string>
#include <algorithm>

#include "Generator.hpp"
#include "Random.hpp"

std::string type, ans;
int sz;
const std::string char_set = "1234567890qwertyuiopasdfghklzxcvbnmQWERTYUIOPASDFGHJLZXCVBNM<>.,;:'\\][{}+=_-()*&^%$#@!~";
const int M = char_set.size();

std::string rand_str(int sz) {
    auto indexes = Random::rnd<uint32_t>(0, M-1, sz);
    std::string a;

    for (auto& it : indexes)
        a.push_back(char_set[it]);
    
    return a;
}

void same_sz() {
    auto k = Random::rnd<uint32_t>(1e5, 1e6);
    auto a = rand_str(k);
    
    Generator::case_in << a << '\n';
    if (ans == "Si") {
        Generator::case_in << a;
    } else {
        auto b = rand_str(k);
        Generator::case_in << b;
    }
}

void same_chr() {
    auto k = Random::rnd<uint32_t>(1e5, 1e6-1);
    auto s_char = char_set[Random::rnd<uint32_t>(0, M-1)];
    
    std::string a;
    a.resize(k, s_char);

    Generator::case_in << a << '\n';
    k = (ans == "Si") ? Random::rnd<uint32_t>(1e5, k) : Random::rnd<uint32_t>(k, 1e6);
    a.resize(k, s_char);
    Generator::case_in << a;
}

void diff_chr() {
    auto k = Random::rnd<uint32_t>(1, M-2);
    auto k2 = Random::rnd<uint32_t>(1, k);
    auto indexes = Random::rnd_unique<uint32_t>(0, M-1, k+1);
    std::string a, b;
    
    for (int i = 0; i < k; i++) {
        int id = indexes[i];
        a.push_back(char_set[id]);
        if (i < k2) b.push_back(char_set[id]);
    }
    
    if (ans == "No") b.push_back(char_set[indexes[k]]);

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    Generator::case_in << a << '\n' << b;
}

void random(uint32_t sz) {
    auto k = Random::rnd<uint32_t>(sz/10, sz);
    auto a = rand_str(k);
    Generator::case_in << a << '\n';
    std::string b;
    
    if (ans == "Si") {
        auto k2 = Random::rnd<uint32_t>(1, k);
        auto idxs = Random::rnd_unique<uint32_t>(0, k-1, k2);
        sort(idxs.begin(), idxs.end());
        for (auto& id : idxs)
            b.push_back(a[id]);
    } else {
        int j = 0;
        while (j < k) {
            auto c = char_set[Random::rnd<uint32_t>(0, M-1)];
            b += c;
            while (j < k && a[j] != c) j++;
            j++;
        }
        auto c = char_set[Random::rnd<uint32_t>(0, M-1)];
        b += c;
    }
    Generator::case_in << b;
}

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    
    Generator::arguments >> type >> ans;
    Generator::case_out << ans;

    if (type == "SameSize") {
        same_sz();
    } else if (type == "SameChar") {
        same_chr();
    } else if (type == "DiffChar") {
        diff_chr();
    } else if (type == "Random") {
        Generator::arguments >> sz;
        random(sz);
    }

    return 0;
}