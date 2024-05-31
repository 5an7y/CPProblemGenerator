#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    string c = b + "#" + a + a;
    int N = a.size();
    auto kmp = prefix_function(c);
    for (int i = 0; i < N; i++) {
        if (kmp[2 * N + i] == N) {
            cout << i;
            return 0;
        }
    }

    return 0;
}