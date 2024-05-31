#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    vector<int> vec(N);
    int maxi = 0, sum = 0;
    for (auto& it : vec) cin >> it, maxi = max(maxi, it);
    for (auto& it : vec) sum += maxi - it;
    cout << sum << '\n';

    return 0;
}