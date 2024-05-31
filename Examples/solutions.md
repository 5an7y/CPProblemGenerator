---
title: Editorial Problem Set X
author: Jose Santiago Vales Mena
date: Marzo 20, 2024
geometry: "left=2cm,right=2cm,top=1.5cm,bottom=1.5cm"
output: pdf_document
---

# A. Problema A

## Problema

Resumen del problema

## Solucion Subtarea 1 (15 puntos)

La primera idea puede ser, para cada elemento, iterar sobre todo el arreglo para ver si existe alguien mayor a él, en cuyo caso lo contamos. Sin embargo, este algoritmo es $O(N^2)$ y debido a los límites de tiempo no es viable.

## Solución

Basta con comparar cada número con el elemento más grande del arreglo. Entonces, podemos encontrar el mayor elemento y contar cuántos son menores.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> vec(N);
    int maxi = 0;

    for (auto& xi : vec) {
        cin >> xi;
        maxi = max(xi, maxi);
    }
    int ans = 0;
    for (auto& xi : vec)
        if (xi < maxi) ans++;

    cout << ans << '\n';
    return 0;
}
```

# B. Problema B
