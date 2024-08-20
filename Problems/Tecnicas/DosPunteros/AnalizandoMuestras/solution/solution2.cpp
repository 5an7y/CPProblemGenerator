#include <bits/stdc++.h>
using namespace std;

int N, sz, pos;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<pair<int, int>> vec(N);

    for(int i = 0; i < N; i++) { 
        cin >> sz;
        vec[i] = {N, N};
        while (sz--) {
            cin >> pos;
            vec[i].first  = min(vec[i].first,  (pos - i + N) % N);
            vec[i].second = min(vec[i].second, (i - pos + N) % N);
        }
    }
    
    sort(vec.begin(), vec.end(), greater<pair<int, int>>());

    int r = 0;
    int ans = vec[0].first;
    for (int l = 0; l < N-1; l++) {
        r = max(r, vec[l].second);
        ans = min(ans, 2 * min(vec[l+1].first, r) + max(vec[l+1].first, r));
    }
    r = max(r, vec[N-1].second);
    ans = min(ans, r);
    
    cout << ans;

    return 0;
}