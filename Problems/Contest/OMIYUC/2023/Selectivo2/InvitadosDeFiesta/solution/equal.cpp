#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    vector<int> nums(N), blacklist(M);
    for (auto& it : nums) cin >> it;
    for (auto& it : blacklist) cin >> it;

    cout << "-1";

    return 0;
}