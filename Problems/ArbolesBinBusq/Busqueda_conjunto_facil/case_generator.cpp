#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <utility>

#include "Generator.hpp"
#include "Random.hpp"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<
    std::pair<int, int>,
    null_type,
    std::less<std::pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

void generate_cases(int Qmax, int Xmax, bool ordered) {
    int Q     = Random::rnd(1, Qmax);
    auto nums = Random::rnd(1, Xmax, Q);
    auto ops  = Random::rnd(1, 2, Q);
    if (ordered) std::sort(ops.begin(), ops.end());

    std::vector<int> inserted_nums, inserted_pos;
    for (int i = 0; i < Q; i++) {
        if (ops[i] == 1) { 
            inserted_nums.push_back(nums[i]); 
            inserted_pos.push_back(i);
        }
        else if (ops[i] == 2 && !inserted_nums.empty() && rand() % 40 == 0) {
            int f = rand() % inserted_nums.size();
            nums[i] = inserted_nums[f];
        }
    }
    sort(inserted_nums.begin(), inserted_nums.end());
    int N = inserted_nums.size();

    ordered_set aux;
    aux.insert({0, N-1});
    for (int i = 0; i < N; i++) {
        int f = Random::rnd<int>(0, aux.size()-1);
        auto[l, r] = *(aux.find_by_order(f));
        int mit = (l + r) / 2;
        nums[inserted_pos[i]] = inserted_nums[mit];
        if (l <= mit - 1) aux.insert({l, mit - 1});
        if (mit + 1 <= r) aux.insert({mit + 1, r});
        aux.erase({l, r});
    }

    Generator::case_in << Q << '\n';
    std::set<int> checker;
    for (int i = 0; i < Q; i++) {
        Generator::case_in << ops[i] << ' ' << nums[i] << '\n';
        if (ops[i] == 1)
            checker.insert(nums[i]);
        else {
            if (checker.count(nums[i])) Generator::case_out << "Si\n";
            else Generator::case_out << "No\n";
        }
    }
    
}

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
        Use Generator::case_in<< to put elements in case input.
        Use Generator::case_out<< to put elements in case output.
        Use Generator::arguments>> to read the arguments.
    */
    std::string type; Generator::arguments >> type;
    int Qmax = 1e6, Xmax = 1e9;
    bool ordered = false;

    if (type == "Qsmall")
        Qmax = 1e3;
    else if (type == "Xsmall")
        Xmax = 1e6;
    else if (type == "Ordered")
        ordered = true;
    
    generate_cases(Qmax, Xmax, ordered);

    return 0;
}