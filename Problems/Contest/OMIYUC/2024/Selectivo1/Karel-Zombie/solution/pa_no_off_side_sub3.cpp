#include <bits/stdc++.h>
using namespace std;

int64_t gauss(int64_t N) {
    return (N) * (N + 1) / 2;
}

int64_t calc_infectados(
    int64_t N, 
    int64_t x,
    int64_t y,
    int64_t D
) { 
    int64_t infectados = D * D + (D-1) * (D-1);
    return infectados;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64_t N, K, x, y;
    cin >> N >> K >> x >> y;

     int d = 1;
    int64_t infectados = calc_infectados(N, x, y, d);
    while (infectados < K) {
        infectados = calc_infectados(N, x, y, ++d);
    }
    cout << d;

    return 0;
}