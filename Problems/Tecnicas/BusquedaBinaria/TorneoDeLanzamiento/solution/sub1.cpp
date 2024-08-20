#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M, D;
    cin >> N >> M >> D;
    int64_t f, a, p;
    cin >> f >> a >> p;

    if (f * a / p >= D) cout << 1;
    else cout << 0;

    return 0;
}