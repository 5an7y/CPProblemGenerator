#include <bits/stdc++.h>
using namespace std;

int N, M, K;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    
    vector<int> nums(N);
    set<int> blacklist;
    
    for (auto& it : nums) cin >> it;
    for (int i = 0; i < M; i++) {
        int a; cin >> a;
        blacklist.insert(a);
    } 

    if (N == M) {
        cout << "-1";
        return 0;
    }

    int sz = 0;
    
    for(auto& it : nums) {
        if (!blacklist.count(it)) {
            cout << it << ' ';
            sz++;
        }
        if (sz == K) break;
    }

    return 0;
}