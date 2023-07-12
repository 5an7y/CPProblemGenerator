#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64_t N, K;
    cin >> N >> K;
    
    priority_queue<tuple<int64_t, int64_t, int64_t>> pq;
    for (int i = 0; i < N; i++) {
        int64_t id, p; cin >> id >> p;
        pq.push({-p, -id, p});
    }

    while (K--) {
        auto[t, id, p] = pq.top();
        pq.pop();
        cout << -id << '\n';
        pq.push({t - p, id, p});
    }

    return 0;
}