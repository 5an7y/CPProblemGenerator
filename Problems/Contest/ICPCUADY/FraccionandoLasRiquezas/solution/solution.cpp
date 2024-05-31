#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; 
    cin >> N;
    vector<int> vec(N);
    for (auto& it : vec) cin >> it;

    sort(vec.begin(), vec.end());
    if (N == 1) {
        cout << 0;
        return 0;
    }

    int64_t ans1 = 0, ans2 = 0;
    for (int i = 0; i < N; i++) {
        ans1 += abs(vec[i] - vec[N/2]);
        ans2 += abs(vec[i] - vec[N/2-1]);
    }

    cout << min(ans1, ans2);

    return 0;
}