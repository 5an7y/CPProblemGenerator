#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64_t N, K, x, y;
    cin >> N >> K >> x >> y;

    int64_t infectados = 0;
    for (int i = 1; i <= N; i++) {
        infectados += i;
        if (infectados >= K) {
            cout << i;
            return 0;
        }
    }

    for (int i = 1; i < N; i++) {
        infectados += N - i;
        if (infectados >= K) {
            cout << i + N;
            return 0;
        }
    }

    return 0;
}