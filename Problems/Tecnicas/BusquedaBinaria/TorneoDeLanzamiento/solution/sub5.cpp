#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M, D;
    cin >> N >> M >> D;
    int64_t f, a;
    int64_t ans = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> f >> a;
        if (f * a >= D) ans += M;
    }

    cout << ans;
    return 0;
}