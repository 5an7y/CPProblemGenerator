#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M, D;
    cin >> N >> M >> D;
    int64_t f, a, p;
    cin >> f >> a;

    int ans = 0;
    for (int i = 0; i < M; i++)  {
        cin >> p;
        if (f * a / p >= D) ans++;
    }

    cout << ans;
    return 0;
}