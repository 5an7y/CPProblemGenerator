# Problema

Dado un arreglo de $N$ números, tu tarea es encontrar el subarreglo* con la suma más grande posible.

*Si tenemos el arreglo $[1, 5, 8, 3, 4]$, un subarreglo es una elección **contigua** de elementos en el arreglo. Por ejemplo, $[5, 8, 3]$, $[1, 5, 8]$, $[5]$, $[3, 4]$, $[1, 5, 8, 3, 4]$ son subarreglos del arreglo original, incluso un arreglo vacío es válido $[]$. No obstante, $[1, 5, 3]$ NO lo es, porque los elementos no están contiguos en el arreglo original y $[8, 5, 1]$ tampoco lo es porque a pesar de estar juntos, su orden está invertido.

# Entrada

Se te dará un número $N$ indicando el tamaño del arreglo. Seguido los $N$ elementos del arreglo $-100 \leq a_i \leq 100$.

# Salida

Deberás imprimir la suma máxima que se puede obtener de un subarreglo.

# Ejemplos

||input
3
3 2 3
||output
8
||description
En este caso si elegimos todo el arreglo obtenemos la respuesta $3 + 2 + 3 = 8$.
||input
5
2 -1 5 -10 2
||output
6
||description
Eligiendo el subarreglo $[2, -1, 5]$ nos da la respuesta.
||input
4
-10 -5 -1 -3
||output
0
||description
El arreglo vacío es la respuesta en este caso.
||end