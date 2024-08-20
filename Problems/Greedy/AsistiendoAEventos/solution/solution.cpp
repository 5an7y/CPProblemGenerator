#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N;

    cin >> N;
    vector<pair<int, int>> vec(N);
    for (auto& [a, b] : vec) cin >> b >> a;
    sort(vec.begin(), vec.end());

    int ans = 0, last_end = -1;
    for (auto& [a, b] : vec) {
        if (last_end < b) {
            ans++;
            last_end = a;
        }
    }

    cout << ans;

    return 0;
}