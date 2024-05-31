# Problema

Santy ha logrado aumentar la popularidad de su escuela mediante un largo proceso, pero ahora quiere hacer un sistema capaz de monitorear la popularidad en todo momento. Esto para poder hacer un análisis más profundo.

La organización encargada de evaluar las escuelas como la de Santy usa un sistema muy peculiar. Se hace un examen de conocimientos generales a todos los alumnos y la **mediana** de los resultados es la calificación de la escuela.

Actualmente tienes $N$ alumnos con calificaciones $a_i$ en el test. Cada día que pasa, todos los alumnos aprenden temas nuevos y, por tanto, su calificación en el test aumenta en 1. Pero además, sucede que cada día que pasa en la escuela un alumno entra o sale. Tu tarea consiste en crear un sistema capaz de procesar esta información y decir la calificación de la escuela (la mediana) durante $Q$ días.

- *Recuerda que la mediana es el elemento que resulta estar en la mitad al ordenar el arreglo de menor a mayor. En caso de tener dos elementos en la mitad se toma el promedio de ambos.

# Entrada

Un entero $1 \leq N \leq 2 \times 10^5$ que indica la cantidad de alumnos en el día 0. Luego, $N$ enteros $1 \leq a_i \leq 10^7$ que representan las calificaciones de los alumnos en ese día.

En la siguiente línea se te proporcionará un número $1 \leq Q \leq 10^5$ que indica la cantidad de días a predecir. En las siguientes $Q$ líneas se te dará una pareja $q_i = 1, -1$ y $1 \leq b_i \leq 10^7 + 10^6$. Que representan:

- Si $q_i = 1$ indica que ingresó un estudiante cuya calificación en ese día es $b_i$.
- Si $q_i = -1$ indica que egresó un estudiante cuya calificación en ese día era $b_i$. Se te asegura que siempre existe un estudiante con esta calificación.

Se te asegura que siempre habra por lo menos un alumno en la escuela.

*Nota: primero se aumentan las calificaciones de todos y después sucede el ingreso o egreso.

# Salida

Para cada día $q_i$ deberás imprimir la calificación de la escuela, incluido el día 0.

# Ejemplos

||input
5
1 1 5 6 5
3
1 6
-1 7
-1 8
||output
5
6
7
6
||description
Al inicio la mediana es $5$, porque si ordenamos las calificaciones nos queda $[1, 1, 5, 5, 6]$.

Luego, todos los alumnos aumentan en 1 e ingresa uno con calificación de 6, entonces, nos queda $[2, 2, 6, 6, 6, 7]$ cuya mediana es $6$ (el promedio de $6$ y $6$).

Para el segundo día todos aumentan en 1 obteniendo $[3, 3, 7, 7, 7, 8]$ y egresa uno con calificación de $7$ dejándonos $[3, 3, 7, 7, 8]$ cuya mediana es $7$.

Finalmente, en el último día todos aumentan en 1 obteniendo $[4, 4, 8, 8, 9]$ pero egresa uno con calificación $8$ y obtenemos $[4, 4, 8, 9]$ cuya mediana son el $4$ y $8$ con una media de $6$.
||input
6
5 29 2 3 95 22
4
1 10
-1 4
1 49
-1 50
||output
13.5
10
17.5
25
19.5
||end