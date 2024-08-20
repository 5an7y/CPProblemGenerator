#include <bits/stdc++.h>
using namespace std;

int N, L;
vector<int> vec;

// Funcion que me dice si existe un subarreglo
// de tamanio al menos L con mediana "median".
bool can_be(int median) {
    int suma = 0, // Suma me lleva la suma del prefijo hasta i
        sumb = 0, // Sumb me lleva la suma del prefijo hasta i - L
        mini = 0; // Mini es el minimo de todos los sumb por los que he pasado

    for (int i = 0; i < L; i++) suma += (vec[i] >= median)? 1 : -1;
    
    for (int i = L; i < N; i++) {
        // Si el prefijo hasta ahora menos el menor sumb
        // ya es positivo entonces si existe el arreglo con dicha mediana.
        if (suma - mini > 0) return true;
        suma += (vec[i] >= median)? 1 : -1;
        sumb += (vec[i-L] >= median)? 1 : -1;
        mini = min(mini, sumb);
    }
    return suma - mini > 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> L;
    vec.resize(N);
    for (auto& it : vec) cin >> it;

    if (can_be(3)) cout << 3;
    else if (can_be(2)) cout << 2;
    else cout << 1;

    return 0;
}