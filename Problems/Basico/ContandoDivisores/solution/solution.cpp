#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, a, b;
    cin >> k >> a >> b;
    cout << b / k - (a - 1)/k;

    return 0;
}