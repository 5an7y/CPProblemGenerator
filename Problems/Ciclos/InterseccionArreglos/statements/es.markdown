# Problema

Se te darán dos arreglos $A$ y $B$ ordenados de menor a mayor. Deberás imprimir la intersección de ambos arreglos. Si un elemento aparece más de una vez en ambos arreglos, deberás imprimirlo con la frecuencia correspondiente.

# Entrada

Un entero $1 \leq N \leq 100$ indicando el tamaño del primer arreglo. En la siguiente línea, $N$ elementos $1 \leq a_i \leq 100$ del primer arreglo ordenados de menor a mayor.

Luego, se te dará el entero $1 \leq M \leq 100$ indicando el tamaño del segundo arreglo y en la siguiente línea los elementos $1 \leq b_i \leq 100$ del arreglo ordenados de menor a mayor.

# Salida

Deberás imprimir la intersección de ambos arreglos. Si no existe intersección, imprimir $-1$.

# Ejemplos

||input
5
3 3 5 6 7
6
2 2 3 3 6 6
||output
3 3 6
||description
Los elementos que aparecen en ambos arreglos son el $3$ y el $6$, pero nota que el $3$ aparece dos veces en ambos.
||input
4
1 2 3 4
4
5 6 7 8
||output
-1
||input
4
1 2 3 4
5
1 2 3 4 5
||output
1 2 3 4
||end