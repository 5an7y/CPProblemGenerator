# Problema

El sudoku es un juego entretenido y desafiante para todas las edades. El principio es bastante sencillo. Tienes una cuadrícula de $9 \times 9$ y deberás llenarla con números entre el $1$ y $9$ con las siguientes consideraciones:

- No puede haber números repetidos en cada fila.
- No puede haber números repetidos en cada columna.
- El tablero se puede dividir en subcuadrados de $3 \times 3$. Dentro de cada subcuadrado no se pueden repetir los números.

Resolver un sudoku no es una tarea sencilla. Sin embargo, el problema esta vez será únicamente revisar si el estado actual del sudoku no infringe alguna de las consideraciones.

# Entrada

Se te dará una matriz de $9 \times 9$ dígitos $0 \leq a_{ij} \leq 9$, la cual representa el estado actual del sudoku. Si $a_{ij} = 0$ indica que no hay número puesto en esa casilla.

# Salida

Imprimir "Si" en caso de que el sudoku sea válido y "No" en caso contrario.

# Ejemplos

||input
5 3 9 8 7 6 4 1 2
7 2 8 3 1 4 9 6 5
6 4 1 2 9 5 7 3 8
4 6 2 5 3 9 8 7 1
3 8 5 7 2 1 6 4 9
1 9 7 4 6 8 2 5 3
2 5 6 1 8 7 3 9 4
9 1 3 6 4 2 5 8 7
8 7 4 9 5 3 1 2 6
||output
Si
||input
5 0 0 8 7 6 4 0 2
0 0 0 3 0 4 9 0 5
6 4 1 2 0 5 7 3 8
0 6 0 0 0 0 0 0 1
0 8 0 7 2 1 0 0 9
0 9 0 4 0 8 0 5 3
2 5 0 1 0 0 0 0 4
9 0 3 6 4 2 5 0 7
8 0 4 9 5 3 1 0 6
||output
Si
||input
5 0 0 8 7 6 4 0 2
0 0 0 3 0 4 9 0 5
6 4 1 2 0 5 7 3 8
0 6 0 0 0 0 0 0 1
8 8 0 7 2 1 0 0 9
0 9 0 4 0 8 0 5 3
0 5 0 1 0 0 0 0 4
9 0 3 6 4 2 5 0 7
8 0 4 9 5 3 1 0 6
||output
No
||input
5 2 0 8 7 6 4 0 2
0 0 0 3 0 4 9 0 5
6 4 1 2 0 5 7 3 8
0 6 0 0 0 0 0 0 1
3 8 0 7 2 1 0 0 9
0 9 0 4 0 8 0 5 3
0 5 0 1 0 0 0 0 4
9 0 3 6 4 2 5 0 7
8 0 4 9 5 3 1 0 6
||output
No
||end
