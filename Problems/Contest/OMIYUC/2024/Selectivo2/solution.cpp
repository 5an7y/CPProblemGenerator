#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> a, b;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;
    a.resize(N);
    b.resize(M);

    for (auto& it : a) cin >> it;
    for (auto& it : b) cin >> it;

    sort(a.begin(), a.end());

    if (a[0] == 0) {
        cout << 0;
        return 0;
    }
    cerr << "Hello" << endl;
    // Cubeta que me indica si este elemento se encuentra en b
    vector<bool> cubeta_b(100001);
    // Cubeta que me indica las apariciones de los multiplos
    vector<int> cubeta_mult(100001);

    // Hacemos la cubeta de b y vemos cuantos elementos distintos tiene
    int diferentes = 0;
    for (auto& it : b) {
        if (cubeta_b[it] == false) {
            diferentes++;
            cubeta_b[it] = true;
        }
    }

    int j = 0,
        dif_cero = 0,
        puntaje = 1000000;
    
    for (int i = 0; i < N; i++) {
        while (j < N && dif_cero < diferentes) {
            // Inserta aj
            int raiz = sqrt(a[j]);
            for (int div = 1; div <= raiz; div++) {
                if (a[j] % div == 0) {
                    int div_op = a[j]/div;
                    // Insertarmos el divisor si aparece en b
                    if (cubeta_b[div]) {
                        if (cubeta_mult[div] == 0) dif_cero++;
                        cubeta_mult[div]++;
                    }
                    // Insertamos el divisor complementario si aparece en b
                    if (cubeta_b[div_op]) {
                        if (cubeta_mult[div_op] == 0) dif_cero++;
                        cubeta_mult[div_op]++;
                    }
                }
            }
            j++;
        }
        if (a[j-1] == a[i]) cout << "a[i] = " << a[i] << '\n';
        if (dif_cero == diferentes)
            puntaje = min(a[j-1] - a[i], puntaje);
        
        // Elimina ai
        int raiz = sqrt(a[i]);
        for (int div = 1; div <= raiz; div++) {
            if (a[i] % div == 0) {
                int div_op = a[i]/div;
                // Eliminamos el divisor si aparece en b
                if (cubeta_b[div]) {
                    cubeta_mult[div]--;
                    if (cubeta_mult[div] == 0) dif_cero--;
                }
                // Eliminamos el divisor complementario si aparece en b
                if (cubeta_b[div_op]) {
                    cubeta_mult[div_op]--;
                    if (cubeta_mult[div_op] == 0) dif_cero--;
                }
            }
        }

    }

    if (puntaje == 1000000) cout << -1;
    else cout << puntaje;

    return 0;
}