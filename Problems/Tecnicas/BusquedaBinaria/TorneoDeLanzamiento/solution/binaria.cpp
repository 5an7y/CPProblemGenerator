#include <bits/stdc++.h>
using namespace std;

int N, M, D;
vector<int64_t> personas;
vector<int64_t> pesos;

int binaria(int ini, int fin, int64_t si) {
    if (ini == fin) return ini;
    int mit = (ini + fin) / 2;
    if (si / pesos[mit] >= D) return binaria(mit + 1, fin, si);
    else return binaria(ini, mit, si);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> D;
    
    personas.resize(N);
    pesos.resize(M);

    for (int i = 0; i < N; i++) {
        cin >> personas[i];
        int64_t x; cin >> x;
        personas[i] *= x;
    }

    for (int i = 0; i < M; i++) cin >> pesos[i];
    sort(pesos.begin(), pesos.end());
    sort(personas.begin(), personas.end());
    
    int64_t ans = 0;
    for (int i = 0; i < N; i++) {
        ans += binaria(0, M, personas[i]);
    }

    cout << ans;

    return 0;
}