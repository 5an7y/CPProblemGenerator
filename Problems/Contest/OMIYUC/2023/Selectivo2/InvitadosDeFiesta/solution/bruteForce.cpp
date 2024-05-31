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

    if (N == M) {
        cout << "-1";
        return 0;
    }

    K = min(K, N - M);
    
    for (int i = 0, it = 0; i < K; it++) {
        bool se_puede = true;
        for (int j = 0; j < M; j++) {
            if (blacklist[j] == nums[it]) {
                se_puede = false;
                break;
            }
        }
        if (se_puede) {
            cout << nums[it] << ' ';
            i++;
        } 
    }

    return 0;
}