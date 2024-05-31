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
    int cantidad_ingredientes, cantidad_amigos, ingredientes_en_pizza;
    Generator::arguments >> cantidad_ingredientes 
                         >> cantidad_amigos 
                         >> ingredientes_en_pizza;
    
    auto ing = Random::rnd_unique(1, 100, cantidad_ingredientes);

    auto whited_ing = Random::rnd_unique(0, cantidad_ingredientes-1, ingredientes_en_pizza);
    for (auto& w_ingridient : whited_ing) w_ingridient = ing[w_ingridient];
    std::vector<int> blacked_ing;

    auto whited_friends = Random::rnd(0, cantidad_amigos);
    std::vector<std::vector<int>> dis_friends;

    for (auto& ingridient : ing) {
        bool esta = false;
        for (auto& w_ingridient : whited_ing) {
            esta = (w_ingridient == ingridient);
            if (esta) break;
        }
        if (!esta) blacked_ing.push_back(ingridient);
    }

    for (int i = 0; i < whited_friends; i++) {
        int k2 = Random::rnd<int>(0, blacked_ing.size());
        auto f_ings = Random::rnd_unique<int>(0, blacked_ing.size() - 1, k2);
        for (auto& f_ing : f_ings) f_ing = blacked_ing[f_ing];
        dis_friends.push_back(f_ings);
    }

    for (int i = whited_friends; i < cantidad_amigos; i++) {
        int k2 = Random::rnd(0, cantidad_ingredientes);
        auto f_ings = Random::rnd_unique(0, cantidad_ingredientes-1, k2);
        for (auto& f_ing : f_ings) f_ing = ing[f_ing];
        dis_friends.push_back(f_ings);
    }

    std::random_shuffle(dis_friends.begin(), dis_friends.end());

    Generator::case_in << cantidad_ingredientes << ' ' << cantidad_amigos << ' ' << ingredientes_en_pizza << '\n';
    for (auto& it : ing) Generator::case_in << it << ' ';
    Generator::case_in << '\n';
    for (auto& friend_ : dis_friends) {
        Generator::case_in << friend_.size() << ' ';
        for (auto& it : friend_) Generator::case_in << it << ' ';
        Generator::case_in << '\n';
    }

    return 0;
}