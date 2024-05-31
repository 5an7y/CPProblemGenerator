# Problema

Ultimamente los alumnos de Yucatan aprendieron a hacer una busqueda binaria. Sin embargo, estos alumnos no suelen poner mucha atencion en clase y la implementaron de una forma un poco distinta a la de Santy, pero funcional

```cpp
bool Binaria(vector<int> a, int x) {
    int l = 0, r = a.size();
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] <= x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    if (left < 0 && a[left - 1] == x) return true;
    else return false;
}
```

Los alumnos recuerdan que Santy les dijo "*esta tecnica unicamente funciona en arreglos ordenados*". Sin embargo, esto no es cierto, ciertamente existe un arreglo no ordenado en donde el algoritmo igual encuentra a $x$. Como buen alumno te has preparado para enfrentarte a Santy, pero quieres marcar un punto, entonces le quieres decir **cuantos arreglos existen que sean una permutacion de los numeros del $1$ al $N$ y la busqueda binaria es capaz de encontrar a $x$ en la posicion $pos$**.

# Entrada

Tres numeros $N$, $X$ y $pos$ descritos en el problema.

# Salida

La cantidad de permutaciones de los elementos del $1$ al $N$ donde la binaria encuentra a $x$ en la posicion $pos$. Como la respuesta puede ser muy grande, imprime modulo $10^9 + 7$.

# Ejemplos

||input
4 1 2
||output
6
||description
Los arreglos serian:

- $(2, 3, 1, 4)$
- $(2, 4, 1, 3)$
- $(3, 2, 1, 4)$
- $(3, 4, 1, 2)$
- $(4, 2, 1, 3)$
- $(4, 3, 1, 2)$
||input
100 42 24
||output
239190862
||end

# Limites

- $1 \leq x \leq N \leq 10^7$
- $0 \leq pos \leq N-1$

**Para un grupo de 10% de los casos**

- $1 \leq N \leq 10$

**Para un grupo de 10% de los casos**

- $pos = x - 1$.

**Para un grupo de 20% de los casos**

- $1 \leq N \leq 15$

**Para un grupo de 30% de los casos**

- $1 \leq N \leq 10^4$

**Para un grupo de 30% de los casos**

- No hay restricciones adicionales