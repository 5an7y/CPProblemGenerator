#include <bits/stdc++.h>
using namespace std;

int64_t a, b, n;

int64_t pot2(int pot) {
    int64_t k = 1;
    while (pot--) {
        k *= 2;
    }
    return k;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b;
    int64_t c = (a + b);
    int64_t up = pot2(n-1)-1,
            down = -pot2(n-1);
    if (down <= c && c <= up) {
        cout << c;
    } else if (c < -pot2(n-1)) {
        cout << up + c - down + 1;
    } else {
        cout << down + c - up - 1;
    }
    return 0;
}