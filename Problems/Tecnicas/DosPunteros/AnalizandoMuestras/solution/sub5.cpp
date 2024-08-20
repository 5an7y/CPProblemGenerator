#include <bits/stdc++.h>
using namespace std;

int N, sz, x;
vector<vector<int>> vec;

bool revisa(int L, int R) {
    int analizados = 0;

    for (int i = 0; i < N; i++) {
        sz = vec[i].size();
        
        bool analizado = false;
        for (int j = 0; j < sz; j++) {
            int movL = (i - vec[i][j] + N) % N;
            int movR = (vec[i][j] - i + N) % N;
            if (movL <= L || movR <= R) analizado = true;
            if (analizado) break;
        }
        if (analizado) analizados++;
    }
    return analizados == N;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    vec.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> sz;
        vec[i].resize(sz);
        for (int j = 0; j < sz; j++) {
            cin >> vec[i][j];
        }
    }

    int ans = N;
    for (int L = 0; L < N; L++) {
        for (int R = 0; R < N; R++) {
            if (revisa(L, R)) 
                ans = min(ans, 2 * min(L, R) + max(L, R));
        }
    }

    cout << ans;
    
    return 0;
}