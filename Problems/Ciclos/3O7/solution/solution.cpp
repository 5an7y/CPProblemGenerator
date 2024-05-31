#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        if (i % 7 == 0 || i % 3 == 0) cout << i << ' ';
    }

    return 0;
}