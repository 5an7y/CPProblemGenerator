# Problema

Tienes $N$ barras de chocolates para repartir entre tus $K$ alumnos. Lamentablemente las barras de chocolate te llegaron muy defectuosas y cada una tiene una longitud de $a_i$. Tus estudiantes son muy exigentes:

- A cada alumno de debes dar un **unico** trozo de chocolate.
- A todos les deberas dar la misma cantidad de chocolate.
- Las barras tienen cuadrados que representan la longitud, por eso mismo, deberas darles una longitud entera de chocolate (posiblemente 0).

¿Cual es la maxima longitud de chocolate que les puedes dar a tus alumnos?

# Entrada

Un entero $N$ representando la cantidad de chocolates y un entero $K$ representando la cantidad de alumnos.

En la siguiente linea tendras $N$ enteros $a_i$ que representan las longitudes de las barras de chocolate.

# Salida

Imprime un unico entero representando la longitud maxima de chocolate que les puedes dar a tus alumnos.

# Ejemplos

||input
3 3
2 3 4
||output
2
||description
Puedes partir todas las barras pero que salga una de $2$ de cada una por lo menos.
||input
4 5
7 5 8 1
||output
3
||end

# Limites

**Para un grupo de 30% de los casos**

- $1 \leq N, K \leq 10^4$
- $1 \leq a_i \leq 10^6$

**Para un grupo de 30% de los casos**

- $1 \leq N, K, a_i \leq 10^5$

**Para un grupo de 40% de los casos**

- $1 \leq N \leq 10^5$
- $1 \leq K, a_i \leq 10^8$