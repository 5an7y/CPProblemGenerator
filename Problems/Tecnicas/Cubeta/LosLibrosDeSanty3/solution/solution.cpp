#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<int> bucket(N+1);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        bucket[x] = i;
    }

    for (int i = 0; i < Q; i++) {
        int x; cin >> x;
        cout << bucket[x] << ' ';
    }

    return 0;
}