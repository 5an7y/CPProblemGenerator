#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int maxi = 0;
    int sum = 0;
    int N;
    cin >> N;
    while (N--) {
        int x; cin >> x;
        sum = max(sum + x, 0);
        maxi = max(maxi, sum);
    }

    cout << maxi << '\n';

    return 0;
}