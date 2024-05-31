#include <bits/stdc++.h>
using namespace std;

int N, M, K, respuesta;
vector<vector<int>> lista_amigos;

void probar(int num) {
    vector <bool> ingredientes_eliminados(100);
    int ingredientes_act = N,
        amigo_act = 0,
        amigos = 0;
    while (num) {
        // Si el bit que corresponde a este amigo esta prendido
        if (num % 2 == 1) {
            amigos++;
            for (auto& ingrediente: lista_amigos[amigo_act]) {
                // Si este ingrediente no ha sido eliminado, reducimos en 1 nuestra
                // cantidad de ingredientes disponibles.
                ingredientes_act -= (ingredientes_eliminados[ingrediente] == false);
                ingredientes_eliminados[ingrediente] = true;
            }
        }
        num /= 2; amigo_act++;
    }

    if (ingredientes_act >= K) respuesta = max(amigos, respuesta);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    // En realidad este vector no es necesario para resolver el problema.
    vector<int> temp(N);
    for (auto& it: temp) cin >> it;
    
    lista_amigos.resize(M);
    for (int i = 0; i < M; i++) {
        int tj; cin >> tj;
        lista_amigos[i].resize(tj);
        for (auto& it : lista_amigos[i]) cin >> it;
    }

    int combinacion_max = pow(2, M);
    for (int i = 15; i < combinacion_max; i++)
        probar(i);

    cout << respuesta;
    return 0;
}