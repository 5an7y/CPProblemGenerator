# Problema

Se te dará un arreglo de $N$ elementos $a_i$. Tu tarea consiste en calcular

$$
\sum_{i=1}^N \sum_{j=i}^N \min\left(a[i..j]\right)
$$

donde $\min\left(a[i..j]\right)$ es el elemento mínimo del subarreglo que comienza en $i$ y termina en $j$.

# Entrada

Un entero $N$ indicando el tamaño del arreglo y en la siguiente línea los elementos del arreglo $a_i$.

# Salida

Deberás imprimir la suma solicitada.

# Ejemplos

||input
3
1 4 2
||output
11
||description
Tenemos los siguientes subarreglos: $[1], [1, 4], [1, 4, 2], [4], [4, 2], [2]$. Si hacemos la suma de los mínimos nos queda $1+1+1+4+2+2=11$.
||input
2
10 11
||output
31
||end

# Límites

- $1 \leq N \leq 10^5$.
- $1 \leq a_i \leq 10^6$.

**Subtarea 1 [15 puntos]**

- El arreglo se encuentra ordenado de menor a mayor.

**Subtarea 2 [15 puntos]**

- $1 \leq N \leq 1000$.

**Subtarea 3 [30 puntos]**

- Todos los elementos del arreglo son distintos.

**Subtarea 4 [40 puntos]** 

- No hay restricciones adicionales.