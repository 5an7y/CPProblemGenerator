# Problema

A Santy le ha dado un dolor de cabeza los apoyos económicos de los estudiantes. Ha sido su primer problema desde que llegó al poder en la Universidad. Finalmente logró resolver el problema de dar apoyos obteniendo el menor desbalance. No obstante, Santy sabe que algún día él dejará de estar al poder en la universidad entonces, te pidió ayuda para crear un sistema que sea capaz de calcular el menor desbalance para hacer todos los montos iguales sufriendo distintas actualizaciones.

Formalmente, tenemos $N$ alumnos inicialmente. Cada alumno recibe un monto económico de $a_i$. Se quiere que todos los alumnos reciban la misma cantidad de apoyo económico sufriendo el menor desbalance posible. Sea $X$ la cantidad que se le dará a todos los alumnos, entonces el desbalance se calcula mediante

$$
\sum_{i=1}^N |a_i - X|.
$$

Además de esto, se sabe que habrán alumnos cuyos montos económicos cambien de ser cierto $a_i$ a un nuevo $b_j$. Tu tarea en este problema es poder calcular el menor desbalance posible después de cada cambio.

# Entrada

Un entero $1 \leq N \leq 2 \times 10^5$ indicando la cantidad de alumnos que reciben el apoyo económico. Luego, $N$ enteros $1 \leq a_i \leq 10^6$ que indica los montos que recibe cada alumno.

En la siguiente línea un entero $1 \leq Q \leq 2 \times 10^5$ que indica la cantidad de cambios a realizar. Luego $Q$ líneas de parejas $(i_j, b_j)$ que indica que al alumno $i_j$ su monto pasa a ser $b_j$.

# Salida

Para cada uno de los cambios deberás imprimir el mínimo desbalance si fuéramos a hacer todos los montos iguales.

# Ejemplos

||input
3
1 100 1
3
1 100
1 1
2 30
||output
99
99
29
||description
En la primera actualización nos cambian el primer elemento por un 100 y nos queda $[100, 100, 1]$. El menor desbalance en esta ocasión resulta de hacer todos iguales a $100$ dando un desbalance de $99$. Luego, se vuelve a su estado original con $[1, 100, 1]$ que el menor desbalance es cuando igualamos todo a $1$. Finalmente, se cambia el segundo elemento por un 30 y nos queda $[1, 30, 1]$ con $29$ como el menor desbalance.
||input
10
1 1 2 2 3 3 4 4 5 5
5
2 6
4 7
6 8
8 9
10 10
||output
13
14
17
20
25
||end