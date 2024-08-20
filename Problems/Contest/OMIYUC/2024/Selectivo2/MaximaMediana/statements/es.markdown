# Problema

Tienes un arreglo de $N$ elementos, tu tarea consiste en encontrar la mediana mas grande que puedes obtener de un subarreglo de tamaño de por lo menos $L$.

La mediana de un arreglo de tamaño $K$ es el elemento que se encuentra la posición $\lfloor (K+1)/2 \rfloor$ después de ordenarlo. Por ejemplo, la mediana de $[1, 2, 1, 2]$ es $1$.

Un subarreglo consiste en tomar un conjunto de elementos *contiguos* de un arreglo. Por ejemplo, si tenemos $[1, 3, 2, 4]$ sabemos que $[3, 2, 4]$ es un subarreglo pero $[1, 2, 4]$ no lo es.

# Entrada

Se te dara un numero $N$ indicando el numero de elementos del arreglo, ademas de un entero $L$ indicando el tamaño minimo del subarreglo.

En la siguiente linea se te daran los $N$ enteros del arreglo.

# Salida

Deberas imprimir la mediana mas grande que puedes obtener.

# Ejemplos

||input
5 3
1 2 3 2 1
||output
2
||input
4 2
1 3 5 2 4
||output
3
||end

# Limites

- $1  \leq L \leq N \leq 10^6$.
- $1 \leq A_i \leq 10^6$.
- Todas las subtareas se encuentran agrupadas

**Subtarea 1 [4 puntos]**

- $L = 1$.

**Subtarea 2 [4 puntos]**

- $L = N$.

**Subtarea 3 [7 puntos]**

- $A_i \leq A_{i+1}$.

**Subtarea 4 [15 puntos]**

- $N \leq 100$.

**Subtarea 5 [15 puntos]**

- $N \leq 10^3$.

**Subtarea 6 [20 puntos]**

- $1 \leq A_i \leq 3$.

**Subtarea 7 [35 puntos]**

- Sin restricciones adicionales.