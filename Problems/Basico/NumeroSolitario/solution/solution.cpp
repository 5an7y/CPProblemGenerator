#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> vec(N);
    for (auto& it : vec) cin >> it;
    for (int i = 0; i < N; i++) {
        bool repetead = false;
        for (int j = 0; j < N; j++) {
            if (vec[i] == vec[j] && i != j) repetead = true;
        }
        if (!repetead) {
            cout << vec[i];
            return 0;
        }
    }

    return 0;
}