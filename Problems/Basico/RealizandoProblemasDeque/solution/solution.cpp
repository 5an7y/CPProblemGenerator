#include <bits/stdc++.h>
using namespace std;

int N, K;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    vector<int> vec(N);
    for (auto& it : vec) cin >> it;

    int l = 0;
    while (l < N && vec[l] < K) l++;
    if (l == N) {
        cout << N;
        return 0;
    }
    int r = N - 1;
    while (vec[r] < K) r--;

    cout << l + (N - 1 - r);

    return 0;
}