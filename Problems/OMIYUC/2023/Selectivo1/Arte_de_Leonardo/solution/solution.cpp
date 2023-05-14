#include <bits/stdc++.h>
using namespace std;

int N, res, fin = 0;
vector<int> vec, pila;
vector<pair<int, int>> limites;

// -------- Funciones Pila ------------- //
void push(int x) { pila[fin++] = x; }
int sz() { return fin; }
int top() { return pila[fin-1]; }
void pop() { pila[--fin] = 0; }
// -------- Funciones Pila ------------- //

int main() {
    int N;
    cin >> N;
    
    vec.resize(N + 2);
    pila.resize(N + 2);
    limites.resize(N + 1, {N+1, 0});

    for (int i = 1; i <= N; i++) {
        cin >> vec[i];
        int color = vec[i];
        limites[color].first  = min(limites[color].first,  i);
        limites[color].second = max(limites[color].second, i);
    }

    vec[0] = vec[N+1] = 0;
    limites[0] = {0, N+1};

    for (int i = 0; i <= N+1; i++) {
        int color = vec[i];

        if (i == limites[color].first) {
            push(color);
            res = max(res, sz());
        }

        if (top() != color) {
            cout << -1 << "\n";
            return 0;
        }

        if (i == limites[color].second)
            pop();
    }

    cout << res - 1 << "\n";
    return 0;
}