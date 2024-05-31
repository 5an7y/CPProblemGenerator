# Problema

Actualmente te encuentras resolviendo una lista de $N$ problemas. Cada problema tiene una dificultad $a_i$. Como buen programador que está empezando, solo puedes resolver problemas cuya dificultad es menor a $K$ (tu habilidad actual).

Tú únicamente resuelves problemas del inicio o del final de la lista, y al resolver un problema lo eliminas de la lista. Tu tarea es determinar la cantidad máxima de problemas que vas a poder resolver.

# Entrada

Dos enteros $1 \leq N, K \leq 100$ indicando la cantidad de problemas y tu nivel de habilidad.

En la siguiente línea, los $N$ enteros $1 \leq a_i \leq 100$ indicando la dificultad de cada problema en el orden en el que aparecen en la lista.

# Salida

La cantidad máxima de problemas que puedes resolver dada las consideraciones hechas.

# Ejemplos

||input
5 3
1 4 2 3 2
||output
2
||description
Solo puedes resolver los problemas en ambos extremos.
||input
9 10
1 7 2 34 5 1 11 4 3
||output
5
||end