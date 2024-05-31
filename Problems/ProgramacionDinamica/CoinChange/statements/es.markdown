# Problema

Tienes un conjunto $C$ de denominaciones de monedas en un país. Supongamos que tienes una cantidad infinita de cada tipo de moneda. Para un valor dado $S$, deseas saber cuántas formas existen para formar ese valor utilizando las monedas disponibles.

# Entrada

Se te proporcionará un número $N$ que indica la cantidad de denominaciones de monedas disponibles. En la siguiente línea, recibirás $N$ números **distintos** que representan las denominaciones de las monedas.

En la última línea, se te dará la cantidad $S$ que deseas formar.

# Salida

Debes imprimir un solo entero que represente la cantidad de formas en las que puedes formar el valor dado. Dado que este número puede ser muy grande, debes imprimir la respuesta módulo $10^9+7$.

# Ejemplos

||input
2
1 2
4
||output
3
||description
La formas que puedes formar el 4 son $\{2, 2\}, \{1, 1, 2\}, \{1, 1, 1, 1\}$.
||input
4
2 5 3 6
10
||output
5
||end

# Limites

- $1 \leq N \leq 100$.
- $1 \leq a_i, S \leq 1000$.

**Para un 50% de los casos**

- $1 \leq N, S, a_i \leq 20$.