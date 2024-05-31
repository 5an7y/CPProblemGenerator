#include <bits/stdc++.h>
using namespace std;

vector<int64_t> vec(3);

int main() {
    for (auto& it : vec) cin >> it;
    sort(vec.begin(), vec.end());
    int64_t ans = 0;
    while (vec[1] > 0 && ! (vec[0] == vec[1] && vec[1] == vec[2])) {
        vec[2] -= 2;
        vec[1] --;
        ans++;
        sort(vec.begin(), vec.end());
    }
    ans += vec[1];
    cout << ans;

    return 0;
}