#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long N, M, K; 
    cin >> N >> M >> K;
    cin >> M;
    bool se_puede = true;
    while (M--) {
        long long x; cin >> x;
        if (x * K <= N) se_puede = false;
    }

    if (!se_puede) cout << "NO\n";
    else cout << "YES\n";

    return 0;
}