#include <bits/stdc++.h>
using namespace std;

int N, K;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    vector<int> vec(N);
    for (auto& it : vec) cin >> it;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (vec[i] + vec[j] == K) {
                cout << "Si";
                return 0;
            }
        }
    }

    cout << "No";

    return 0;
}