#include <bits/stdc++.h>
using namespace std;

// La pila guarda la posicion del elemento menor
// es decir, guarda i en lugar de a_i.
stack<int> pila;

int N;
vector<int> vec;

// Este vector guarda los li y ri.
// El first de la pareja corresponde a li y el second a ri.
vector<pair<int, int>> ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    vec.resize(N);
    ans.resize(N);
    for (auto& it : vec) cin >> it;

    for (int i = 0; i < N; i++) {
        int it = vec[i];
        while ( (!pila.empty()) && vec[pila.top()] >= it) {
            pila.pop();
        }
        if (pila.empty()) ans[i].first = 0;
        else ans[i].first = pila.top() + 1;
        pila.push(i);
    }

    while (!pila.empty()) pila.pop();

    for (int i = N-1; i >= 0; i--) {
        auto it = vec[i];
        while ((!pila.empty()) && vec[pila.top()] > it)
            pila.pop();
        if (pila.empty()) ans[i].second = N - 1;
        else ans[i].second = pila.top() - 1;
        pila.push(i);
    }

    int64_t suma = 0;
    for (int i = 0; i < N; i++) {
        suma += (int64_t)vec[i] * 
                (int64_t)(i - ans[i].first + 1) * 
                (int64_t)(ans[i].second - i + 1);
    }
    cout << suma << '\n';

    return 0;
}