#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int64_t, bool>>> DP;
vector<int64_t> vec;

int64_t solve(int i, int j, bool first_p = true) {
    if (i == j) {
        if (first_p) return vec[i];
        else return -vec[i];
    }
    if (!DP[i][j].second) { 
        DP[i][j].second = true;
        if (first_p) 
            DP[i][j].first = max(solve(i, j-1, !first_p) + vec[j], solve(i + 1, j, !first_p) + vec[i]);
        else 
            DP[i][j].first = min(solve(i, j-1, !first_p) - vec[j], solve(i + 1, j, !first_p) - vec[i]);
    }
    return DP[i][j].first;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    DP.resize(N);
    for (auto& it: DP) it.resize(N);
    vec.resize(N);
    for (auto& it : vec) cin >> it;
    cout << solve(0, N-1) << '\n';

    return 0;
}