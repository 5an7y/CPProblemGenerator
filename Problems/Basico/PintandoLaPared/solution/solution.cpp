#include <bits/stdc++.h>
using namespace std;
 
int T, M, igual, mayor;
long long N, K, techo; 
bool se_puede;
long long x;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M >> K;
    se_puede = true;
    mayor = igual = 0;
    techo = N / K + 1;

    while (M--) {
        cin >> x;
        if (x == techo) igual++;
        if (x > techo) mayor++;
    }

    if (mayor == 0 && igual <= N % K) cout << "SI\n";
    else cout << "NO\n";

    return 0;
}