# Problema

Se te dará un arreglo de $N$ elementos y $Q$ preguntas de la forma "¿Este elemento se encuentra dentro del arreglo?".

# Entrada

Un entero $1 \leq N \leq 100$ indicando la cantidad de elementos en el arreglo. En la siguiente línea se te darán los elementos del arreglo $1 \leq a_i \leq 100$.

Luego, se te dará un entero $1 \leq Q \leq 100$ indicando la cantidad de preguntas que se te harán. Seguido se te darán $Q$ números $1 \leq q_i \leq 100$ de los cuales deberás indicar si se encuentran en el arreglo.

# Salida

Para cada una de las preguntas deberás imprimir "S" en caso de que el número se encuentre y "N" en caso contrario, en líneas separadas.

# Ejemplos

||input
6
8 3 3 4 2 1
4
2
9
3
10
||output
S
N
S
N
||description
El primer elemento que nos preguntan es el 2, el cual sí se encuentra en el arreglo. Luego, el 9 no se encuentra, el 3 sí se encuentra y finalmente el 10 no se encuentra.
||input
5
1 2 3 4 5
5
4 5 6 7 8
||output
S
S
N
N
N
||end