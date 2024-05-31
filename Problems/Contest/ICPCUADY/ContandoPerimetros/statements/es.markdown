# Problema

Santy ya lleva un mes al poder en la Universidad y ha logrado grandes cambios con los apoyos económicos. Ahora, es momento de reformar la estructura de la escuela en sí. La universidad no cuenta con mucha iluminación, por eso Santy quiere poner una cinta LED (como la que usan los gamers) alrededor de toda la escuela.

Sin embargo, para poder hacer esto, necesita saber cuánto mide el perímetro de la escuela. Por suerte, se tiene un mapa completo de la escuela. Además, la escuela es un área completamente conectada (no tiene huecos en medio). Tu tarea será determinar el perímetro de la escuela.

El mapa de la escuela consiste en un rectángulo de $N \times M$ donde cada espacio puede o no pertenecer a la estructura de la universidad.

# Entrada

Se te darán los enteros $1 \leq N, M \leq 1000$ que indican las dimensiones del mapa. Luego se te darán enteros $a_{i, j} = 0, 1$ que representan el mapa. Un 0 indica que ese espacio no le pertenece a la universidad y un 1 indica que sí. Cada espacio mide 1 unidad de alto y una de ancho.

# Salida

Deberás imprimir un entero indicando el perímetro de la universidad.

# Ejemplos

||input
4 4
0 0 0 0
0 1 1 0
0 1 1 0
0 1 1 0
||output
10
||description
Un rectángulo de 3 de altura y 2 de ancho nos da un perímetro de 10.
||input
3 5
0 0 1 0 0
0 1 1 1 0
1 1 1 1 1
||output
16
||input
5 4
0 1 1 1
0 1 0 0
0 1 1 1
0 1 0 0
0 1 1 1
||output
24
||end

# Clarificación

Que el mapa no tenga huecos en medio quiere decir que todo el área externa es conectada. Es decir, no pueden darse casos como

||input
5 5
0 0 0 0 0
0 1 1 1 0
0 1 0 1 0
0 1 1 1 0 
0 0 0 0 0
||output
||input
3 3
0 1 0
1 0 1 
0 1 1 
||output
||end
