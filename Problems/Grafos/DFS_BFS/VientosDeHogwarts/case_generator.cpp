#include <iostream>
#include "Generator.hpp"
#include "Random.hpp"

std::vector<bool> visited;
std::vector<int> act_component;
std::vector<std::vector<int>> adj;

void dfs(int node) {
    for(auto& n_node : adj[node]) {
        if (!visited[n_node]) {
            visited[n_node] = true;
            act_component.push_back(n_node);
            dfs(n_node);
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
    int N, trees; std::string casos;
    Generator::arguments >> N >> trees >> casos;
    auto forest = Random::rnd_forest(N, trees);
    int M = forest.size();
    std::vector<int> velas(N, 0);

    visited.resize(N, false);
    adj.resize(N);

    for (auto& [a, b] : forest) adj[a].push_back(b), adj[b].push_back(a);
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            act_component = {i};
            dfs(i);

            if(Random::rnd(0, 1)) {
                int k = act_component.size();
                int choosen = Random::rnd(0, k-1);
                velas[act_component[choosen]] = 1;
            } else {
                if (casos == "FULL") for (auto& it : act_component) velas[it] = 1;
                else for (auto& it : act_component) velas[it] = Random::rnd(0, 1);
            }
        }
    }

    Generator::case_in << N << " " << M << '\n';
    for (auto& it : velas) Generator::case_in << it << ' ';
    Generator::case_in << '\n';
    for (auto& [a, b] : forest) Generator::case_in << a + 1 << ' ' << b + 1<< '\n';
    return 0;
}