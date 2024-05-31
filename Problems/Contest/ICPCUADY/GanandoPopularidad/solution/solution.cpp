#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> vec;
int64_t K;

bool canbe(int64_t k2) {
    int64_t min_need = 0;
    for (int i = N/2; i < N; i++) {
        min_need += max((int64_t)0, k2 - vec[i]);
        if (min_need > K) return false;
    }
    return min_need <= K;
}

int64_t binary(int64_t a, int64_t b) {
    if (a == b) return a;
    int64_t mit = (a + b)/2;
    if (canbe(mit)) {
        return binary(mit+1, b);
    } else {
        return binary(a, mit);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    vec.resize(N);
    for (auto& it : vec) cin >> it;
    cin >> K;
    sort(vec.begin(), vec.end());

    cout << binary(vec[N/2], K + vec[N/2] + 1)-1;

    return 0;
}