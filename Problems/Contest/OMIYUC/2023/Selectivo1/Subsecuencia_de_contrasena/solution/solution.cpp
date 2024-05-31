#include <bits/stdc++.h>
using namespace std;

string a, b;
int N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;

    N = a.size();
    M = b.size();

    for (int i = 0, j = 0; i < M; i++, j++) {
        while (j < N && a[j] != b[i]) j++;
        if (j == N) {
            cout << "No";
            return 0;
        }
    }

    cout << "Si";
    return 0;
}