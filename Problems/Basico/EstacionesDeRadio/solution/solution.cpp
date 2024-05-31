#include <bits/stdc++.h>
using namespace std;

vector<int> estaciones = {420, 661, 854, 1111, 1360, 1519};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int X;
    cin >> X;

    if (X < 340 || 1850 < X) {
        cout << "Sin Servicio";
        return 0;
    }
    if (X < estaciones[0]) {
        cout << "Adelante " << estaciones[0] - X;
        return 0;
    }
    if (estaciones[5] < X) {
        cout << "Atras " << X - estaciones[5];
        return 0;
    }
    for (int i = 0; i < 5; i++) {
        if (estaciones[i] <= X && X <= estaciones[i+1]) {
            if (X == estaciones[i] || X == estaciones[i+1]) {
                cout << "0";
                return 0;
            }
            int atras = X - estaciones[i];
            int adelante = estaciones[i+1] - X;
            if (atras < adelante) {
                cout << "Atras " << atras;
            } else {
                cout << "Adelante " << adelante;
            }
            return 0;
        }
    }

    return 0;
}