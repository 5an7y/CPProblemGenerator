#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M, D;
    cin >> N >> M >> D;
    vector<int64_t> f(N), a(N), p(M);
    
    for (int i = 0; i < N; i++) {
        cin >> f[i] >> a[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> p[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (f[i] * a[i] / p[j] >= D) ans++;
        }
    } 

    cout << ans;
    return 0;
}