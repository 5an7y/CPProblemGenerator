#include <bits/stdc++.h>
using namespace std;

void Solve() {
    int N; cin >> N;
    vector<pair<int, int>> parejas(2*N);
    for (int i = 0; i < N; i++) {
        cin >> parejas[2 * i].first, parejas[2 * i].second = -1;
        cin >> parejas[2 * i + 1].first, parejas[2 * i + 1].second = 1;
    }
    sort(parejas.begin(), parejas.end());
    int maxi = 0, act = 0;
    for (int i = 0; i < 2 * N; i++) {
        act -= parejas[i].second;
        maxi = max(maxi, act);
    }
    cout << maxi << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int Tc = 1; //cin >> Tc;
    while (Tc--) Solve();

    return 0;
}