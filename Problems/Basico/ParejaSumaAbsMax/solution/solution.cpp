#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int max_sum = 0;
    cin >> N;
    vector<int> vec(N);
    for (auto& it : vec) cin >> it;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            max_sum = std::max(max_sum, abs(vec[i] + vec[j]));
        }
    }

    cout << max_sum;

    return 0;
}