#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int a, b, c, d;
    
    cin >> a >> b;
    c = (a + b) % 10;
    d = (b + c) % 10;
    cout << a << " " << b << " " << c << " " << d << " ";

    while (!(c == a && d == b)) {
        c = (d + c) % 10;
        swap(d, c);
        cout << d << " ";
    }

    return 0;
}