#include <bits/stdc++.h>
using namespace std;

int64_t a, b, n, up_limit, down_limit;
uint64_t aa, bb, cc, limit;
bool isneg = false;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b;
    if (a == 0 || b == 0 || a/abs(a) != b/abs(b)) {
        cout << a + b << '\n';
        return 0;
    }
    if (a < 0) {
        aa = -(a + 1);
        aa++;
        bb = -(b + 1);
        bb++;
        isneg = true;
    } else {
        aa = a;
        bb = b;
    }
    cc = aa + bb;
    
    limit = 1;
    limit = limit << (n-1);
    up_limit = limit - 1;
    down_limit = -limit;

    if (isneg) {
        if (cc <= limit) {
            cout << -cc;
        } else {
            cc -= limit;
            cout << up_limit - (cc - 1);
        }
    } else {
        if (cc <= limit-1) {
            cout << cc;
        } else {
            cc -= limit-1;
            cout << down_limit + cc - 1;
        }
    }
    return 0;
}