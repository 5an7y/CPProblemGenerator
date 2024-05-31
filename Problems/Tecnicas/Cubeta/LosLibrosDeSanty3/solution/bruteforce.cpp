#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    for (int i = 0; i < Q; i++) {
        int x; cin >> x;
        for (int j = 0; j < N; j++) {
            if (vec[j] == x) {
                cout << j << ' ';
                break;
            }
        }
    }

    return 0;
}