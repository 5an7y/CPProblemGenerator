#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    map<int, int> bucket;
 
    int N; cin >> N;
    int x, ans = 1;
    while (N--) {
        cin >> x;
        for (int i = 1; i <= sqrt(x); i++) {
            if (x % i == 0) {
                if (++bucket[i] == 2) ans = max(ans, i);
                if (x / i != i) {
                    if (++bucket[x / i] == 2) ans = max(ans, x/i);
                }
            }
        }
    }
 
    cout << ans;
 
    return 0;
}
