#include <bits/stdc++.h>
using namespace std;

vector<vector<int64_t>> DP;
vector<int64_t> vec;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    DP.resize(N);
    for (auto& it: DP) it.resize(2);
    vec.resize(N);

    for (auto& it : vec) cin >> it;

    for (int sz = 0; sz < N; sz++) {
        bool first_p = ( (N - (sz + 1)) % 2 == 0 );
        for (int i = 0; i + sz < N; i++) {
            if (sz == 0)
                DP[i][first_p] = (2 * first_p - 1) * vec[i];
            else {
                if (first_p) 
                    DP[i][first_p] = max( DP[i][!first_p] + vec[i + sz], DP[i + 1][!first_p] + vec[i]);
                else 
                    DP[i][first_p] = min( DP[i][!first_p] - vec[i + sz], DP[i + 1][!first_p] - vec[i]);
            }
        }
    }

    cout << DP[0][true] << '\n';

    return 0;
}