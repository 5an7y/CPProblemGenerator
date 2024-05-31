#include <bits/stdc++.h>
using namespace std;

int N, K, r, k;
int ar[10];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    cout << N * N * N;

    cin >> N;

    for (int i = 0; i < N; i) {
        for (int j = 0; j * j < N; j++) {
            ar[(j+i) %  N] += r+i;
        }
    }

    for (int i = 1; i < N; i++) {
        ar[i] -= ar[i-1];
    }

    for (int i = 0; i < N; i++) {
        cout << ar[i] << ' ';
    }

    return 0;
}