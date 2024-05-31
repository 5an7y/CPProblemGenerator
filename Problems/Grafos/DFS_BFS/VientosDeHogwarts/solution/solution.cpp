#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> velas;
int64_t velas_act, ans;

bool dfs(int nodo) {
    bool has_window_below = velas[nodo];

    for (auto& n_node : adj[nodo]) {
        if (!visited[n_node]) {
            visited[n_node] = true;
            velas_act += velas[n_node];
            has_window_below |= dfs(n_node);
        }
    }
    if (has_window_below) ans++;
    return has_window_below;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64_t pasadisos = 0, cuartos = 0;
    int N, M; 
    cin >> N >> M;
    
    velas.resize(N);
    adj.resize(N); visited.resize(N);

    for (auto& it: velas) cin >> it;
    while (M--) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < N; i++) {
        if ( (!visited[i]) && velas[i] == 1) {
            visited[i] = true;
            velas_act = velas[i];
            ans = 0;
            dfs(i);
            if (velas_act <= 1) continue;
            pasadisos += velas_act * (velas_act - 1) / 2;
            cuartos += ans;
        }
    }

    cout << pasadisos << " " << cuartos;

    return 0;
}