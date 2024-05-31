#include <bits/stdc++.h>
using namespace std;

long long infiltrados(long long x) {
    if (x < 0) return 0;
    vector<bool> binario;
    long long x2 = x;
    while (x) binario.push_back(x % 2), x/=2;
    reverse(binario.begin(), binario.end());
    
    long long ans = 1, 
              N = binario.size(), 
              M = (N + 1) / 2, 
              number = 0;

    long long pot2[N+1];
    pot2[0] = 1;
    for (int i = 1; i <= N; i++) pot2[i] = pot2[i-1] * 2;

    for (int i = 1; i < N; i++)
        ans += pot2[(i - 1) / 2];

    number += pot2[N - 1] + 1;
    for (int i = 1; i < M; i++) {
        if (binario[i]) {
            ans += pot2[M - i - 1];
            number += pot2[i] + (N - i - 1 != i) * pot2[N - i - 1];
        }
    }
    ans += number <= x2;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a, b;
    cin >> a >> b;
    cout << infiltrados(b) - infiltrados(a-1);


    return 0;
}