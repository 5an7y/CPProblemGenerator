#include <iostream>
#include "Generator.hpp"
#include "Random.hpp"

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
 
typedef tree<
    pair<int, int>,
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

int main(int argc, char *argv[]) {
    Generator::init_generator(argc, argv);    
    /*
        Use Generator::case_in<< to put elements in case input.
        Use Generator::case_out<< to put elements in case output.
        Use Generator::arguments>> to read the arguments.
    */
    // Read types
    int N, K, Q;
    string type; 
    Generator::arguments >> N >> K >> Q >> type;
    
    // Fill vector and tree
    auto vec = Random::rnd(1, K, N);
    ordered_set S;
    int t = 0;
    for(auto& it : vec) S.insert({it, t++});

    // Print vector
    Generator::case_in << N << '\n';
    for(auto& it : vec) Generator::case_in << it << ' ';

    int sz = N;
    Generator::case_in << '\n' << Q << '\n';
    for (int i = 0; i < Q; i++) {
        int choice = Random::rnd(0, 1);
        if (choice == 0) choice--;
        if (sz == 1 || type == "ALLIN") choice = 1;
        if (type == "ALLOUT") choice = -1;

        if (choice == -1) {
            int r = Random::rnd(0, sz-1);
            int el = S.find_by_order(r)->first;
            int key = S.find_by_order(r)->second;
            Generator::case_in << choice << ' ' << el + i + 1 << '\n';
            S.erase({el, key});
            sz--;
        } else {
            int r = Random::rnd(1, K + i + 1);
            Generator::case_in << choice << ' ' << r << '\n';
            S.insert({r - i - 1, t++});
            sz++;
        }
    }

    return 0;
}