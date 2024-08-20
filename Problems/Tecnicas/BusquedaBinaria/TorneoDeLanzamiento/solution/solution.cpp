#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M, D;
    cin >> N >> M >> D;
    vector<int64_t> personas(N);
    vector<int64_t> pesos(M);
    for (int i = 0; i < N; i++) {
        cin >> personas[i];
        int64_t x; cin >> x;
        personas[i] *= x;
    }

    for (int i = 0; i < M; i++) cin >> pesos[i];
    sort(pesos.begin(), pesos.end());
    sort(personas.begin(), personas.end());
    
    int64_t ans = 0;
    for (int i = 0, j = 0; i < N; i++) {
        while (j < M && personas[i] / pesos[j] >= D) j++;
        ans += j;
    }

    cout << ans;

    return 0;
}