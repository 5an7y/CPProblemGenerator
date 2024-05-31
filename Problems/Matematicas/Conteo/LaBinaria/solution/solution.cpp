#include <bits/stdc++.h>
using namespace std;

unordered_set<int> menores, mayores;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64_t n, x, pos;
    cin >> n >> x >> pos;

    int left = 0, right = n;
    while (left < right) {
        int middle = (left + right) / 2;
        if (pos > middle) menores.insert(middle), left = middle + 1;
        else if (pos < middle) mayores.insert(middle), right = middle;
        else left = middle + 1;
    }
    
    int64_t formas = 1;
    if (menores.size() >= x || mayores.size() > (n - x)) formas = 0;
    int64_t libres = n - 1 - menores.size() - mayores.size();
    int64_t mod = 1e9 + 7;
    for (int64_t i = 0; i < menores.size(); i++) formas = (formas * (x - 1 - i)) % mod;
    for (int64_t i = 0; i < mayores.size(); i++) formas = (formas * (n - x - i)) % mod;
    for (int64_t i = 1; i <= libres; i++) formas = (formas * i) % mod;
    cout << formas << '\n';
    return 0;
} 