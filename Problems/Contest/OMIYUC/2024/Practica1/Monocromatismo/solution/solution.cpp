#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, K; cin >> N >> K;

    int ar[N], puntuaciones[K + 1];
    for (int i = 1; i <= K; i++) puntuaciones[i] = -1; 
    for (int i = 0; i < N; i++) {
        cin >> ar[i];
        puntuaciones[ar[i]] = 0;
    }

    int act = N-1;
    for (int i = K; i > 0; i--) {
        while (act >= 0 && ar[act] > i) act--;
        if (puntuaciones[i] >= 0) puntuaciones[i] += act;
    }

    act = 0;
    for (int i = K; i > 0; i--) {
        while (act < N && ar[act] > i) act++;
        if (puntuaciones[i] >= 0) puntuaciones[i] = 2 * (puntuaciones[i] - act + 1);
    }

    for (int i = 1; i <= K; i++) 
        if (puntuaciones[i] == -1) cout << 0 << ' ';
        else cout << puntuaciones[i] << ' ';

    return 0;
}