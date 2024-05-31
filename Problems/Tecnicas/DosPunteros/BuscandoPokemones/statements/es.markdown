# Problema

Ash es el entrenador Pokémon más reconocido de toda la historia. Pero no todo entrenador Pokémon reconocido puede superar el desafío que tenga delante. Actualmente, Ash se encuentra frente a una hilera de $N$ arbustos. El arbusto $i$ contiene al Pokémon $x_i$, representado por una letra del alfabeto inglés, y desde el arbusto $i$ te puedes mover al $i + 1$ y al $i - 1$, excepto en los extremos para los cuales ya no hay más arbustos.

Una vez que entras en un arbusto, debes moverte a lo largo de la hilera y al salir no puedes volver a entrar de nuevo. Ash quiere saber cuál es la menor cantidad de movimientos que debe hacer para atrapar la mayor cantidad de Pokémon *distintos* posible.

# Entrada

Se te dará un número $1 \leq N \leq 10^5$ indicando la cantidad de arbustos en la hilera, en la siguiente línea se te dará una cadena de caracteres de tamaño $N$ representando los Pokémon que hay en cada arbusto.

# Salida

Deberás imprimir la cantidad mínima de movimientos que Ash debe realizar dentro de los arbustos para alcanzar el objetivo.

# Ejemplos

||input
3
AaA
||output
2
||description
Ash puede empezar en el arbusto 1 y moverse al 2.
||input
7
bcAAcbc
||output
3
||description
Ash puede empezar desde el 4 hasta el 6.
||input
6
aaBCCe
||output
5
||end