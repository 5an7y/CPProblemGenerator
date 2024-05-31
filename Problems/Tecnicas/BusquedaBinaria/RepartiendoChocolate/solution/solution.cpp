#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> chocolates;

bool check(int longitud) {
    if (longitud == 0) return true;
    int suma = 0;
    for (auto& it : chocolates) {
        suma += it / longitud;
        if (suma >= K) return true;
    }
    return false;
} 

int binaria(int ini, int fin) {
    if (ini == fin) return ini;
    int mit = (ini + fin) / 2;
    if (!check(mit)) return binaria(ini, mit);
    else return binaria(mit + 1, fin);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    chocolates.resize(N);
    int maxi = 0;
    for (auto& it: chocolates) cin >> it, maxi = max(maxi, it);
    cout << binaria(0, maxi) - 1;
    return 0;
}