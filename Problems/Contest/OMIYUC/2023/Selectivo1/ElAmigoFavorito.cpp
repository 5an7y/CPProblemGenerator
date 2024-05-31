#include <bits/stdc++.h>
using namespace std;

int64_t N, D, K;

int64_t Gauss(int64_t x) {return x * (x + 1) / 2;}

bool puedo_dar(int64_t P) {
    int64_t amigos_izquierda = K - 1,
            amigos_derecha   = N - K,
            dulces_izquierda,
            dulces_derecha,
            dulces_total;
    
    dulces_izquierda = (amigos_izquierda >= P - 1) ? (Gauss(P-1) + amigos_izquierda - (P - 1)) : (Gauss(P-1) - Gauss(P - 1 - amigos_izquierda));
    dulces_derecha   = (amigos_derecha >= P - 1)   ? (Gauss(P-1) + amigos_derecha - (P - 1))   : (Gauss(P-1) - Gauss(P - 1 - amigos_derecha));
    dulces_total = dulces_izquierda + P + dulces_derecha;
    
    return dulces_total <= D;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> D >> K;

    int ini = 0, fin = D + 1;
    while (ini != fin) {
        int mit = (ini + fin) / 2;
        if (puedo_dar(mit))
            ini = mit + 1;
        else
            fin = mit;
    }
    cout << ini - 1;
    return 0;
}