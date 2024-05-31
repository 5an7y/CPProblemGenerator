#include <bits/stdc++.h>
using namespace std;

long long gauss(long long a) {
    return a * (a + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long N, K, suma_act = 1, carta_act = 1;
    cin >> N >> K;
    while (suma_act != N) {
        if (carta_act < K && suma_act + gauss(carta_act + 1) <= N) {
            cout << 'S';
            suma_act += ++carta_act;
        } else if (suma_act + gauss(carta_act) <= N) {
            cout << 'I';
            suma_act += carta_act;
        } else {
            cout << 'B';
            suma_act += --carta_act;
        }
    }

    return 0;
}