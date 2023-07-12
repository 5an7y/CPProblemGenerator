#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    map<string, int> mapeo;
    int maxi = 0;
    while(N--) {
        string s; cin >> s;
        maxi = max(maxi, ++mapeo[s]);
    }

    for (auto& [key, val] : mapeo) {
        if (val == maxi) {
            cout << key << '\n';
            return 0;
        }
    }
    
    return 0;
}