#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int A;
    cin >> A;
    int sum = 0;
    while(A) {
        sum += A % 10;
        A /= 10;
    }

    cout << sum << '\n';

    return 0;
}