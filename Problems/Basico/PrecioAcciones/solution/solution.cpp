#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int suma = 0;
    int ant = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (i) suma += max(0, x - ant);
        ant = x;
    }

    cout << suma;

    return 0;
}