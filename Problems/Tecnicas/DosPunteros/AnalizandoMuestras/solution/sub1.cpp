#include <bits/stdc++.h>
using namespace std;

int N, sz, en_lista, x;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    en_lista = 0;
    for (int i = 0; i < N; i++) {
        cin >> sz;
        while (sz--) {
            cin >> x;
            if (x == i) en_lista++;
        }
    }

    if (en_lista == N) cout << 0;
    else cout << 1;

    return 0;
}