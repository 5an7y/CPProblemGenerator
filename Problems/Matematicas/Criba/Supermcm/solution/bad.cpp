#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int64_t> vec(N);
    for (auto& it : vec) cin >> it;
    const int mod = 1e9 + 7;    

    int64_t lcm = vec[0];
    for (int i = 1; i < N; i++) {
        lcm /= __gcd(lcm, vec[i]);
        lcm *= vec[i];
        lcm %= mod;
    }

    cout << lcm;
    return 0;
}