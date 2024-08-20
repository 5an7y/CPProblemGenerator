#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N; 
    cin >> N;
    vector<vector<int>> adj(2*N + 1);

    for(int i = 0; i < N; i++) {
        int li; cin >> li;
        for (int j = 0; j < li; j++) {
            int pos; cin >> pos;
            int r = (pos - i + N) % N;
            int l = (N - r) % N;
            adj[N + r].push_back(i);
            if (l > 0)
                adj[N - l].push_back(i);
        }
    }
    vector<int> cubeta(N);
    int pointer2 = N, distintos = 0;

    for (int i = 0; i <= N; i++) {
        for (auto& idx : adj[i]) {
            if (cubeta[idx]++ == 0)
                distintos++;
        }
    }

    int ans = N;
    for (int i = 1; i <= N; i++) {
        
        for (auto& idx : adj[i-1]) {
            if (--cubeta[idx] == 0)
                distintos--;
        }
        
        while (distintos < N) {
            pointer2++;
            for (auto& idx : adj[pointer2]) {
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