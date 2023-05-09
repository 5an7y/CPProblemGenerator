#include <bits/stdc++.h>
using namespace std;

int N, res;
vector<int> vec;
vector<pair<int, int>> limites;
stack<int> st;

int main() {
    int N;
    cin >> N;
    
    vec.resize(N + 2);
    limites.resize(N + 1, {N+1, 0});

    for (int i = 1; i <= N; i++) {
        cin >> vec[i];
        int color = vec[i];
        limites[color].first  = min(limites[color].first,  i);
        limites[color].second = max(limites[color].second, i);
    }

    vec[0] = vec[N+1] = 0;
    limites[0] = {0, N+1};

    for (int i = 0; i <= N+1; i++) {
        int color = vec[i];

        if (i == limites[color].first) {
            st.push(color);
            res = max(res, (int)st.size());
        }

        if (st.top() != color) {
            cout << -1 << "\n";
            return 0;
        }

        if (i == limites[color].second)
            st.pop();
    }

    cout << res - 1 << "\n";
    return 0;
}