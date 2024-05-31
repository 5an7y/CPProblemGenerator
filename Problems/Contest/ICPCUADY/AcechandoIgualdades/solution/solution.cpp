#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<int, int> mapeo;
    int N;
    cin >> N;
    int N2 = N;
    int maxi = 0;
    while (N2--) {
        int x; cin >> x;
        maxi = max(maxi, ++mapeo[x]);
    }

    cout << N - maxi << '\n';

    return 0;
}