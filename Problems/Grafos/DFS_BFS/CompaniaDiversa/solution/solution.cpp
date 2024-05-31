#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
int n_components;
vector<vector<int>> united, adj;

void dfs(int act_node) {
    for (auto& n_node : adj[act_node]) {
        if (!visited[n_node]) {
            visited[n_node] = true;
            dfs(n_node);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    
    visited.resize(N);
    united.resize(M + 1);
    adj.resize(N);

    int maxi = 0;
    for (int i = 0; i < N; i++) {
        int k; cin >> k;
        maxi = max(maxi, k);
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            united[x].push_back(i);
        }
    }

    for (int i = 1; i <= M; i++) {
        int k = united[i].size();
        if (k <= 1) continue;
        for (int j = 0; j < k; j++) {
            int j1 = (j + 1) % k;
            adj[united[i][j]].push_back(united[i][j1]);
            adj[united[i][j1]].push_back(united[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            n_components++;
            visited[i] = true;
            dfs(i);
        }
    }

    cout << n_components - 1 * (maxi > 0);

    return 0;
}