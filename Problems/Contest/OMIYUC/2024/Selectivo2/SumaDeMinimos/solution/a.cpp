#include <bits/stdc++.h>
using namespace std;

int N, L;
vector<int> vec;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> L;
    vec.resize(N);
    for (auto& it : vec) cin >> it;

    int maxi = -1;
    for (int i = 0; i < N; i++) {
        multiset<int> menores, mayores;
        for (int j = i; j < N; j++) {
            // Pasamos el menor de los mayores al conjunto de los menores
            if (!mayores.empty()) {
                menores.insert(*mayores.begin());
                mayores.erase(mayores.begin());
            }
            // Insertamos el nuevo elementos
            menores.insert(vec[j]);
            // Vamos pasando elementos de los menores al conjunto de los
            // mayores hasta tener mas mayores.
            while (menores.size() >= mayores.size()) {
                auto it = menores.end();
                it--;
                mayores.insert(*it);
                menores.erase(it);
            }
            // La mediana se encuentra como el menor elemento de los mayores.
            if (j - i + 1 >= L)
                maxi = max(maxi, *mayores.begin());
        }
    }

    cout << maxi;

    return 0;
}