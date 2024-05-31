#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, a, b;
    cin >> k >> a >> b;
    int ans = 0;
    for (int i = a; i <= b; i++) {
        if (i % k == 0) {
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}