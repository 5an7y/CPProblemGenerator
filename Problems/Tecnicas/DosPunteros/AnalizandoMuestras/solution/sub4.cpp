#include <bits/stdc++.h>
using namespace std;

int N, sz, x;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int mini = N;
        cin >> sz;
        while (sz--) {
            cin >> x;
            mini = min(mini, x - i);
        }
        ans = max(ans, mini);
    }

    cout << ans;
    return 0;
}