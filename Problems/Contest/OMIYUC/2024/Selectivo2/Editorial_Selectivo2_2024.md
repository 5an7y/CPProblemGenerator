---
title: "Solución Selectivo OMI Yucatan - 2"
author: José Santiago Vales Mena
date: Agosto 10, 2024
geometry: margin=2cm
output: pdf_document
header-includes:
    - \usepackage{setspace}
    - \onehalfspacing
---


# A. Overflow

## Subtarea 1 [10 puntos]

Como la suma no hacer overflow podemos hacer una suma sencilla de números. Recuerda usar `long long` para los numeros grandes.

```cpp
#include <bits/stdc++.h>
using namespace std;

int64_t n, a, b;

int main() {
    cin >> n >> a >> b;
    cout << a + b;
    return 0;
}
```

## Subtarea 2 [15 puntos] y 3 [15 puntos]

La suma de dos números de $n$ bits la puede soportar un número cono $n+1$ bits. Esto quiere decir que para estas subtareas podemos hacer la suma de los números sin problema y luego ver donde recaes el overflow ya que la suma sigue estando dentro de un `long long`(`int64_t`) o un `int` (la diferencia entre la subtarea 2 y 3 es si se usa `int` en lugar de `long long`). 

Si hay *overflow* entonces, es menor al limite inferior o es mayor al limite superior. Para el caso de que sea mayor al limite superior solo hay que calcular la diferencia $k = 2^{n-1} - (a + b)$ y simplemente el numerp donde cae son $k-1$ posiciones delante del limite inferior, es decir, $ans = -2^{n-1} + (k-1)$.

```cpp
#include <bits/stdc++.h>
using namespace std;

int64_t a, b, n;

// Funcion que calcula una potencia de 2
int64_t pot2(int pot) {
    int64_t k = 1;
    while (pot--) {
        k *= 2;
    }
    return k;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b;
    // Obtenemos la suma
    int64_t c = a + b;
    // Limites inferiores y superiores
    int64_t limite_superior = pot2(n-1)-1,
            limite_inferior = -pot2(n-1);

    // Si NO hay overflow sacamos la suma normal
    if (limite_inferior <= c && c <= limite_superior) {
        cout << c;
    // SI el overflow es por abajo
    } else if (c < -pot2(n-1)) {
        cout << limite_superior + (c - limite_inferior + 1);
    } else {
        cout << limite_inferior + (c - limite_superior - 1);
    }
    return 0;
}
```

## Solucion 4 [100 puntos]

El codigo a **la solucion anterior en realidad da los 100 puntos** ¿Por qué? El único problema que uno puede pensar es cuando $n=64$ que es justamente el limite de los `long long` (`int64_t`). Para empezar $2^{63}$ es un número que no puede representar. No obstante, lo bueno de c++ es que justamente para ese caso el propio compilador se encarga de hacer el overflow, entonces, todas las operaciones que hacemos funcionan como esperamos y dan el resultado correcto.

Sin embargo, existe otra solución haciendo uso de enteros grandes sin signo si lo quisieramos hacer de la forma *"correcta"* pero hay que tener mucho cuidado con como manejamos las operaciones y las conversiones entre tipos.

```cpp
#include <bits/stdc++.h>
using namespace std;

int64_t a, b, n, up_limit, down_limit;
uint64_t aa, bb, cc, limit;
bool isneg = false;

uint64_t pot2(uint64_t k) {
    uint64_t a = 1;
    while (k--) {
        a *= 2;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b;
    if (a == 0 || b == 0 || a/abs(a) != b/abs(b)) {
        cout << a + b << '\n';
        return 0;
    }
    if (a < 0) {
        aa = -(a + 1);
        aa++;
        bb = -(b + 1);
        bb++;
        isneg = true;
    } else {
        aa = a;
        bb = b;
    }
    cc = aa + bb;
    
    limit = 1;
    limit = pot2(n-1);
    up_limit = limit - 1;
    down_limit = -(int64_t)(limit - 1) - 1;

    if (isneg) {
        if (cc <= limit) {
            cout << -cc;
        } else {
            cc -= limit;
            cout << up_limit - (cc - 1);
        }
    } else {
        if (cc <= limit-1) {
            cout << cc;
        } else {
            cc -= limit-1;
            cout << down_limit + (int64_t)(cc) - 1;
        }
    }
    return 0;
}
```

# B. Suma de minimos

## Subtarea 1 [15 puntos]

Una parte clave del problema esta en cambiar la pregunta. En lugar de responder *Cual es el elemento minimo para cada subarreglo?* nos debemos preguntar *Para cada elemento, en cuantos subarreglos este es el minimo*. Entonces, nuestra suma se vuelve unicamente el elemento multiplicado por la cantidad de subarreglos donde este es el minimo (llamemos a este numero $g(a_i)$).

$$
\sum_{i=0}^{N-1} a_i * g(a_i)
$$

Cuando estan ordenados de menor a mayor la respuesta es sencilla el elemento en la posicion $i$ es el minimo para todos los subarreglos $a[i...j]$ donde $i \leq j \leq N-1$. Es decir, hay $N - i$, subarreglos donde este es el minimo. Entonces, el problema solo es calcular 

$$
\sum_{i=0}^{N-1} a_i * (N - i).
$$

Usemos enteros grandes ya que la suma puede ser muy grande ($N^2 \times \max(a_i) = (10^5)^2 \times 10^6 = 10^16$).

```cpp
#include <bits/stdc++.h>
using namespace std;

int N;
int64_t ai, ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for (int64_t i = 0; i < N; i++) { 
        cin >> ai;
        ans += ai * (N - i);
    }
    cout << ans;

    return 0;
}
```

## Subtarea 2 [15 puntos]

Esta subtarea consiste en hacer la fuerza bruta, para todos los subarreglos calculamos el minimo y lo sumamos.

```cpp
#include <bits/stdc++.h>
using namespace std;

int N;
int64_t ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;

    vector<int> vec(N);
    for (auto& it : vec) cin >> it;

    for (int i = 0; i < N; i++) { 
        int mini = vec[i];
        for (int j = i; j < N; j++) {
            mini = min(mini, vec[j]);
            ans += mini;
        }
    }
    cout << ans;

    return 0;
}
```

Este tiene una complejidad de $O(N^2)$, ya que visitamos todos los subarreglos, por eso da TLE en las demas subtareas.

## Subtarea 3 [30 puntos]

Retomemos la idea de calcular $g(a_i)$ para cada elemento en el arreglo. Al principio parece una idea complicada, sin embargo, lo que podemos hacer es calculcar *el area donde este elemento es el minimo* o dicho de otra forma *el subarreglo mas grande donde un elemento es el minimo*.

Para eso basta encontrar el primer elemento a la izquierda que es menor a $a_i$ y el primero a la derecha. Si recorremos el arreglo por cada elementos volvemos a lo mismo de tener una solucion $O(N^2)$, asi que debemos ser un poco mas inteligentes. Justamente este problema se puede resolver haciendo uso de una *min-stack*, donde llevamos una pila de los elementos mas chicos encontrados hasta el momento y cuando llega un elemento menor sacamos a todos los que son mayores a el en la pila y el elemento que queda arriba es justamente el primero a la izquierda que es menor.

Hacemos un barrido de izquierda y otro a la derecha para encontrar los limites de cada lado. Una vez hecho esto obtenemos números $l_i$ y $r_i$ que es el rango donde el elemento es el minimo. Ahora para contar $g(a_i)$ basta ver cuantos subarreglo contienen a $a_i$ y sus limites estan entre $l_i$ y $r_i$. Esto es una sencilla aplicacion del principio multiplicativo, el inicio de nuestro rango puedes ser cualquier elementos entre $l_i$ y e $i$ y nuestro final del rango puede ser cualquier elemento entre la posicion $i$ hasta $r_i$. Es decir, tenemos $i - l_i+1$ opciones para el inicio y $r_i - i + 1$ opciones para el final, dando un total de $g(a_i) = (i - l_i+1) * (r_i - i + 1)$. 

Finalmente nuestra respuesta ahora solo se basa en calcular

$$
\sum_{i=0}^{N-1} a_i * (i - l_i+1) * (r_i - i + 1).
$$

Hacer la busqueda de los $l_i$ y $r_i$ es lineal gracias a la *min-stack* y sacar la suma igual es lineal dandonos una complejidad de $O(N)$.

```cpp
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
        while ( (!pila.empty()) && vec[pila.top()] > it) {
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
```

## Solucion [100 puntos]

El problema de la solucion anterior es que la busqueda del rango se detiene cuando encuentra el primer elemento menor o igual que el. Entonces, si hay dos elementos iguales, los rangos que contienen a ambos y ellos son el minimo, nunca son contados.

Si lo limitamos a que se detenga en el primero que sea menor estricto, el problema se volveria que cuenta el rango multiples veces. 

Para solucionar esto, lo unico que debemos hacer es que uno de los lados (digamos el izquierdo) se detenga en el menor estricto y el otro lado en el primero menor o igual. De esta forma *damos preferencia* a que el minimo de cada rango sea el menor que encuentra mas a la derecha (o izquierda si lo haces al reves) y ahora si estariamos bien todos los rangos.

```cpp
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
        // Mira la condicion de aqui es >=
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
        // La condicion de aqui es solo >
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
```

# C. RQCDC

El problema te pide encontrar un subconjunto del arreglo $a$ tal que para todos los elementos en $b$ haya por lo menos un multiplo del mismo. Ademas quieres el subconjunto tal que la diferencia con el elemento maximo menos el minimo sea lo menor posible.

## Subtarea 1 [5 puntos]

Para esta subtarea solo hay un elemento en $b$, por lo que, si logramos encontrar un multiplo del elemento en $b$ ese mismo seria nuestra respuesta y si no, pues no hay subconjuntos buenos y la respuesta es $-1$. Nada mas hay que tener cuidado con el $0$. Para eso se crea una funcion que determina si un numero divide a otro.

```cpp
#include <bits/stdc++.h>
using namespace std;

int N, M;
 
// x divide a y?
bool divide(int x, int y) {
    if (x != 0) return y % x == 0;
    else return y == 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;
    vector<int> a(N), b(M);
    for (auto& it : a) cin >> it;
    for (auto& it : b) cin >> it;

    for (auto& it : a) {
        if (divide(b[0], it)) {
            cout << 0;
            return 0;
        }
    }

    cout << -1;
    return 0;
}
```

## Subtarea 2 [5 puntos]

Ahora solo tenemos un numero en $a$. Entonces, si todos los numeros en $b$ lo dividen significa que el elemento por si solo es bueno, si no, es que no hay subconjunto bueno.

```cpp
#include <bits/stdc++.h>
using namespace std;

int N, M;
 
// x divide a y?
bool divide(int x, int y) {
    if (x != 0) return y % x == 0;
    else return y == 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;
    vector<int> a(N), b(M);
    for (auto& it : a) cin >> it;
    for (auto& it : b) cin >> it;

    bool ans = true;
    // Si alguno no cumple el bool se vuelve falso siempre
    for (auto& it : b)
        ans &= divide(it, a[0]);

    if (ans) cout << 0;
    else cout << -1;

    return 0;
}
```

## Subtarea 3 [5 puntos]

En este caso todos los numeros son potencias de $2$. Lo bueno de esto es que si una potencia de dos divide a un numero, entoces cualquier otra menor igual lo va a dividir. Es decir, si $64$ divide a un numero entonces tanto $1, 2, 4, 8, 32$ igual van a dividir a ese numero. 

Entonces, si queremos que todos los elementos en $b$ dividan a los numeros en el subconjuto basta con que el elemento mas grande divida a los numeros. Entonces, basta con que el elemento mas grande en $b$ tenga algun multiplo en $a$.

```cpp
#include <bits/stdc++.h>
using namespace std;

int N, M;
 
// x divide a y?
bool divide(int x, int y) {
    if (x != 0) return y % x == 0;
    else return y == 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;
    vector<int> a(N), b(M);
    for (auto& it : a) cin >> it;
    for (auto& it : b) cin >> it;

    int x = 0;
    for (auto& it : b)
        x = max(x, it);

    for (auto& it : a) {
        if (divide(x, it)) {
            cout << 0;
            return 0;
        }
    }

    cout << -1;
    return 0;
}
```

## Subtarea 4 [10 puntos]

Una observacion clave para resolver el problema es que si ordenamos el arreglo $a$, entonces, cualquier subarreglo es candidato a ser subconjunto. Al final del dia lo que queremos minimizar es la diferencia entre el elemento maximo y el minimo; entonces, el subconjunto $[2, 8]$ tiene el mismo puntaje que el subcojunto $[2, 4, 6, 7, 8]$ y el hecho de incluir mas elementos solo aumenta las posibilidades de que ese subconjunto sea bueno.

Entonces, una idea es para todos los subarreglos de $a$ ordenado, hacemos un chequeo si es bueno en cuyo caso calculamos su *puntaje* y solo tomamos el minimo puntaje entre todos los arreglos.

```cpp
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> a, b;

// x divide a y?
bool divide(int x, int y) {
    if (x != 0) return y % x == 0;
    else return y == 0;
}

bool es_bueno(int i, int j) {
    for (auto& it : b) {
        // Verificamos si el elemento tiene un multiplo en el subconjunto
        bool tiene_mult = false;
        for (int k = i; k <= j; k++)
            if (divide(it, a[k])) tiene_mult = true;
        
        if (!tiene_mult) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;
    a.resize(N);
    b.resize(M);

    for (auto& it : a) cin >> it;
    for (auto& it : b) cin >> it;

    int puntaje = 1000000;
    sort(a.begin(), a.end());
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (es_bueno(i, j)) {
                puntaje = min(puntaje, a[j] - a[i]);
            }
        }
    }

    if (puntaje == 1000000) cout << -1;
    else cout << puntaje;

    return 0;
}
```

La complejidad de esto es $O(N^3M)$ ya que por cada subarreglo ($N^2$) estamos haciendo un chequeo que nos cuesta $NM$.

## Subtarea 5 [12 puntos]

En este caso todos los numeros de $b$ se encuentran en $a$ y ademas todos los numeros son primos. Eso quiere decir que el unico posible multiplo de cada elemento de $b$ es el mismo que se encuentra en $a$.

Entonces, la respuesta es el subconjunto que contiene a todos los elementos de $b$ cuyo puntaje es exactamente el elemento mas grande menos el elemento mas chico de $b$.

```cpp
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

    sort(b.begin(), b.end());

    cout << b.back() - b.front();

    return 0;
}
```

OJO, si los numeros no fueran todos primos esto no seria cierta, por ejemplo si $a = [2, 4, 5]$ y $b = [2, 5]$ la respuesta optima es el subconjunto $[4, 5]$.

## Subtarea 6 [18 puntos]

Como todos los numeros son primos sucede lo mismo que antes, el unico posible subconjunto bueno es el que contiene todos los elementos de $b$. Pero ahora no nos aseguran que esten, por lo que, debemos verificar que todos los elementos de $b$ se encuentren en $a$ de caso contrario nuestra respuesta es $-1$.

Podemos hacer la tecnica que mas nos guste, dos punteros o una cubeta, en este caso usaremos un `set` como cubeta.

```cpp
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

    sort(b.begin(), b.end());

    set<int> cubeta;
    for(auto& it : b) cubeta.insert(it);
    for (auto& it : a) 
        if (cubeta.count(it)) cubeta.erase(it);

    if (cubeta.empty()) cout << b.back() - b.front();
    else cout << -1;

    return 0;
}
```

## Subtarea 7 [20 puntos]

Para esta subtarea retomemos la idea de la subtarea 4 de ir probando subarreglos ordenados de $a$ para encontrar uno optimo. El problema de la subtarea 4 es que probabamos todos los subarreglos y probabarlos tarda mucho tiempo.

¿Que tecnica nos ayuda a encontrar subarreglos que cumplan una propiedad? Un ventana deslizante. Entonces, si nosotros conocemos si un arreglo $a[i...j]$ es bueno o malo, debemos encontrar una forma de verificar si $a[i...j+1]$ es bueno o malo, sin tener que volver a calcular todo. 

Mas aun, para cada uno de los $i$, unicamente nos interesa el primer $j$ donde el subarreglo es bueno. Entonces, vamos a empezar con el primer elemento, luego vamos a ir abriendo nuestra ventana hacia la derecha hasta que el subarreglo que queramos sea bueno. Una vez hacemos eso, igual debemos buscar la forma de reutilizar esa informacion para calcular la respuesta de $i+1$. Es decir, movemos en una posicion nuestro inicio y ahora con la informacion ya obtenida calcular hasta donde tenemos que abrir la ventana a partir de alli para obtener la respuesta.

¿Si yo tengo un subarreglo como puedo ir haciendole para insertar, eliminar elementos y saber si es un buen subarreglo? Bueno, pues una idea es que cada elemento de $b$ tenga una cubeta interna que le diga cuantos multiplos hay actualmente en el subarreglo elegido.

Insertar o eliminar un elemento solo hay que ir por todos los elementos de $b$ y actualizar. Sabremos si un subarreglo es bueno o no si todos los elementos son diferentes a cero. Podemos tener un contador sencillo para saber eso.

```cpp
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> a, b;

// x divide a y?
bool divide(int x, int y) {
    if (x != 0) return y % x == 0;
    else return y == 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;
    a.resize(N);
    b.resize(M);

    for (auto& it : a) cin >> it;
    for (auto& it : b) cin >> it;

    sort(a.begin(), a.end());

    vector<int> cubeta_mult(M);
    int j = 0,
        dif_cero = 0,
        puntaje = 1000000;
    
    for (int i = 0; i < N; i++) {
        while (j < N && dif_cero < M) {
            // Inserta aj
            for (int k = 0; k < M; k++) {
                if (divide(b[k], a[j])) {
                    if (cubeta_mult[k] == 0) dif_cero++;
                    cubeta_mult[k]++;
                }
            }
            j++;
        }

        if (dif_cero == M)
            puntaje = min(a[j-1] - a[i], puntaje);
        
        // Elimina ai
        for (int k = 0; k < M; k++) {
            if (divide(b[k], a[i])) {
                cubeta_mult[k]--;
                if (cubeta_mult[k] == 0) dif_cero--;
            }
        }

    }

    if (puntaje == 1000000) cout << -1;
    else cout << puntaje;

    return 0;
}
```

Eliminar o inserta un elemento nos cuesta $O(M)$ luego, por la naturaleza de la ventana deslizante hay que hacer $O(N)$ de esas operaciones, dandonos una complejidad total de $O(NM)$.

## Solucion [100 puntos]

Para esta subtarea hay que buscar como reducir la operacion insertar o eliminar de la subtarea anterior. La optimizacion se basa en lugar de tener que iterar sobre todos los elementos de $b$ y ver si son divisores de $a_i$, mejor iteramos sobre todos los divisores de $a_i$ y vemos si se encuentran dentro de $b$. Para esto usaremos una cubeta.

Para iterar sobre todos los divisores de $a_i$ unicamente debemos buscar sobre los elementos hasta $\sqrt{a_i}$ y si encontramos un divisor podemos deducir el otro. Solo hay que tener cuidado con el $0$. Si hay un $0$ en $a$ ese es la solucion. Tambien manejar con cuidado los elementos repetidos en $b$.

```cpp
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
        }

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
```

De esta forma la complejidad pasa a ser $O(N \sqrt{\max(A_i)})$ que si entra en tiempo. Si usamos una estructura como un `set` o `map` para la cubeta, nuestra complejidad sube a $O(N \sqrt{\max(A_i)} \log (M))$ que ya no entraria en tiempo.

# D. Maxima Mediana

## Subtarea 1 [4 puntos]

Puedo elegir el subarreglo que tenga al elemento maximo y ese sera la respuesta.

```cpp
#include <bits/stdc++.h>
using namespace std;

int N, L;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> L;
    int maxi = -1;

    while (N--) {
        int aux;
        cin >> aux;
        maxi = max(aux, maxi);
    }
    cout << maxi;

    return 0;
}
```

## Subtarea 2 [4 puntos]

El unico subarreglo que puedo elegir es todo el arreglo. Por lo tanto, solo debo calcular la mediana del arreglo.

```cpp
#include <bits/stdc++.h>
using namespace std;

int N, L;
vector<int> vec;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> L;
    vec.resize(N);
    for (auto& it : vec) cin >> it;
    sort(vec.begin(), vec.end());

    cout << vec[(N-1)/2];

    return 0;
}
```

## Subtarea 3 [7 puntos]

Como los elementos estan ordenados, lo mejor que podemos hacer es tomar los ultimos $L$ elementos del arreglo original y eso nos da la mayor mediana.

```cpp
#include <bits/stdc++.h>
using namespace std;

int N, L;
vector<int> vec;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> L;
    vec.resize(N);
    for (auto& it : vec) cin >> it;

    cout << vec[N - 1 - L/2];

    return 0;
}
```

## Subtarea 4 [15 puntos]

Podemos aplicar un algoritmo de fuerza bruta e iterar sobre todos los subarreglos de tamaño por los menos $L$ y calcular su mediana para ver cual es la mayor que podemos obtener.

```cpp
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
        vector<int> aux;
        for (int j = i; j < N; j++) {
            aux.push_back(vec[j]);
            if (j - i + 1 >= L) {
                sort(aux.begin(), aux.end());
                maxi = max(maxi, aux[(j-i)/2]);
            }
        }
    }

    cout << maxi;

    return 0;
}
```

Esta solucion implicar que por cada uno de los subarreglos $O(N^2)$ hagamos un ordenamiento $O(N \log N)$ dandonos una complejidad total de $O(N^3 \log N)$.

## Subtarea 5 [15 puntos]

La solucion a esta subtarea consiste en hacerle una optimizacion a la subtarea anterior, debemos ser capacez de encontrar la mediana de un subarreglo mientras le insertamos elementos. De esta forma no tenemos que reordenar todo el subarreglo cada que insertamos un nuevo elemento. Esto lo podemos hacer de diversas formas, una de ellas es llevan un `multiset` que lleve los $n/2$ elementos mas chicos y otros que lleve los $n/2$ elementos mas grandes.

Cuando insertamos un nuevo elementos solo es mover un elemento del multiset a otro en el peor de los casos que resulta ser una operacion logaritmica $O(\log N)$.

```cpp
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
```

De esta forma conseguimos reducir la complejidad a $O(N^2 \log N)$

## Subtarea 6 [20 puntos]

En este caso la respuesta solo puede ser $1, 2$ o $3$. Si la respuesa no es $2$ o $3$ debe ser $1$. ¿Como verificamos si existe un subarreglo donde la mediana es el $3$?

Necesitamos un subarreglo de tamaño $k \geq L$ donde mas de la mitad de sus elementos sean $3$. Volvamos a cambiar un poco el objetivo, hagamos un arreglo $b$ donde todos los elementos que sean menores a $3$ podemos pensarlos como $-1$s, por otro lado, todos los elementos que sean $3$ vamos a pensarlos como $1$s. Ahora, queremos ver si existe algun subarreglo de tamaño al menos $L$ que sume un numero positivo ¿Como podemos ver si este subarreglo existe?

Haremos uso de una suma de prefijos. Sea $pref$ el arreglo de suma de prefijos de $b$. Sabemos que la suma de cualquier subarreglo es representada por la diferencia entre un elemento de $pref$ con su anterior.

Ahora digamos que queremos ver si existe un subarreglo que termina en una posicion $i$ de tamano al menos $L$ que sume algo positivo. Entonces, basta ver en nuestra suma de prefijos si existe un elemento $L$ o mas posiciones atras cuya diferencia con el elemento en $i$ sea positivo. Para no complicarnos la vida, podemos simplemente tomar el elemento mas chico, si con ese podemos lograr un numero positivo, entonces, si existe el subarreglo.

Por lo tanto, podemos aplicar esta logica para todas las posiciones y usar una tecnica de dos punteros para ver si existe un subarreglo que sume algo positivo. 

Si no existe, repetimos el proceso con el $2$ y si tampoco existe la respuesta es $1$.

```cpp
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
```

Esto es $O(N)$ ya que solo debemos hacer dos recorridos al arreglo de prefijos.

## Solucion [100 puntos]

Aplicar lo mismo que la anterior subtarea pero para cada uno de los elementos del arreglo nos puede llevar a una complejidad de $O(N^2)$.

No obstante, lo que nos responde nuestra funcion `can_be(median)` es si existe un subarreglo donde la mediana es *al menos* `median`. ¿Notan alguna propiedad de esta funcion?

Es binaria, para todos los elementos antes de cierto numero este responde `true` y a apartir de un elemento siempre va a responder `false`. Entonces, buscar la mediana mas grande que puedo formar es equivalente a buscar el ultimo elemento que me de `true` en la funcion.

```cpp
#include <bits/stdc++.h>
using namespace std;

int N, L;
vector<int> nums;

bool can_be(int median) {
    int suma = 0, sumb = 0, mini = 0;
    for (int i = 0; i < L; i++) suma += (nums[i] >= median)? 1 : -1;
    for (int i = L; i < N; i++) {
        if (suma - mini > 0) return true;
        suma += (nums[i] >= median)? 1 : -1;
        sumb += (nums[i-L] >= median)? 1 : -1;
        mini = min(mini, sumb);
    }
    return suma - mini > 0;
}

int binaria(int ini, int fin) {
    if (ini == fin) return ini;
    int mit = (ini + fin) / 2;
    if (can_be(mit)) return binaria(mit + 1, fin);
    return binaria(ini, mit);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> L;
    nums.resize(N);
    int maxi = 0;
    for (auto& it : nums) cin >> it, maxi = max(it, maxi);

    cout << binaria(0, maxi+1) - 1;

    return 0;
}
```

Y esto nos da una complejidad de $O(N \log N)$.