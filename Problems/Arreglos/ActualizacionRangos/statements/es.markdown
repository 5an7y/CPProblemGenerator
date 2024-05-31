# Problema

Tienes un arreglo de tamaño $N$, se te darán $K$ actualizaciones de la forma "A los números desde la posición $l_i$ hasta $r_i$ aumentarlos en 1".

# Entrada

Se te dará un número $1 \leq N \leq 100$ indicando la cantidad de elementos en el arreglo. En la siguiente línea se te darán los elementos del arreglo $1 \leq a_i \leq 100$.

Luego se te dará el número de actualizaciones a realizar $1 \leq K \leq 20$ y $K$ líneas de parejas de números indicando el rango de la actualización $1 \leq l_i \leq r_i \leq N$.

# Salida

Deberás mostrar el arreglo después de todas las actualizaciones.

# Ejemplos

||input
6
7 3 9 2 1 4
3
1 3
3 3
2 4
||output
8 5 12 3 1 4
||description
El arreglo originalmente es $7 3 9 2 1 4$.

La primera actualización nos pide aumentar en 1 desde la posición 1 hasta la 3. Entonces el arreglo nos queda como $8, 4, 10, 2, 1, 4$.

La siguiente actualización solo nos aumenta en 1 el elemento en la tercera posición $8, 4, 11, 2, 1, 4$.

Finalmente, la última actualización nos aumenta en 1 desde la posición 2 hasta la 4, $8, 5, 12, 3, 1, 4$.
||input
5
1 2 3 4 5
1
1 5
||output
2 3 4 5 6
||end