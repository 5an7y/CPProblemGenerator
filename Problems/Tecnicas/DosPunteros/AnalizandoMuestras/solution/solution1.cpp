#include <bits/stdc++.h>
using namespace std;

int N, sz, pos;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<vector<int>> adj(2*N + 1);

    for(int i = 0; i < N; i++) { 
        cin >> sz;
        for (int j = 0; j < sz; j++) { 
            cin >> pos;
            int r = (pos - i + N) % N;
            int l = (N - r) % N;
            // Aqui unimos las dos listas de la posicion 
            // [0, N-1] son rotaciones de L y  de la 
            // [N + 1, 2 * N - 1] son rotaciones de R.
            adj[N + r].push_back(i);
            if (l > 0)
                adj[N - l].push_back(i);
        }
    }
    vector<int> cubeta(N);
    int pointer2 = N, distintos = 0;

    // Contamos el hacer L rotaciones a la izquierda.
    for (int i = 0; i <= N; i++) {
        sz = adj[i].size();
        for (int j = 0; j < sz; j++) {
            int idx = adj[i][j];
            if (cubeta[idx]++ == 0)
                distintos++;
        }
    }

    int ans = N;
    for (int i = 1; i <= N; i++) {

        // Eliminamos la fila i-1
        sz = adj[i-1].size();
        for (int j = 0; j < sz; j++) {
            int idx = adj[i-1][j];
            if (--cubeta[idx] == 0)
                distintos--;
        }

        // Agregramos la fila pointer2 hasta tener todas analizadas
        while (distintos < N) {
            pointer2++;
            sz = adj[pointer2].size();
            for (int j = 0; j < sz; j++) {
                int idx = adj[pointer2][j];
                if (cubeta[idx]++ == 0)
                    distintos++;
            }
        }
        int act_ans = 2 * min(N - i, pointer2 - N) + max(N - i, pointer2 - N);
        ans = min(ans, act_ans);
    }

    cout << ans;

    return 0;
}