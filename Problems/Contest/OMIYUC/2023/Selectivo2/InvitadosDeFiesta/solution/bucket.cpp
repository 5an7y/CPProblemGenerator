#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    vector<int> nums(N);
    vector<bool> bucket(1000001);
    for (auto& it : nums) cin >> it;
    for (int i = 0; i < M; i++) {
        int a; cin >> a;
        bucket[a] = true;
    } 

    if (N == M) {
        cout << "-1";
        return 0;
    }

    int sz = 0;
    
    for(auto& it : nums) {
        if (!bucket[it]) {
            cout << it << ' ';
            sz++;
        }
        if (sz == K) break;
    }

    return 0;
}