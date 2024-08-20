#include <bits/stdc++.h>
using namespace std;

vector<int> vec = {500, 200, 100, 50, 20, 10, 5, 2, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x; cin >> x;
    int s = 0;
    for (auto& it : vec) {
        s += x / it;
        x %= it;
    }
    cout << s;

    return 0;
}