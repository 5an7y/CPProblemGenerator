# Problema

Santy se ha dado cuenta de que tiene que hacer recortes de presupuesto en su universidad, y uno de esos recortes será en los apoyos que reciben los alumnos destacados. Al principio, cada alumno recibía cierta cantidad de apoyo $a_i$, y la escuela decidió hacer esto más justo haciendo que todos reciban la misma cantidad, aumentando el apoyo de todos. Sin embargo, después de un tiempo y tantas cosas que la universidad está realizando, se dio cuenta de que no es un modelo sustentable y decidió renovarlo.

Se quiere proponer un nuevo monto igualitario (que a todos les toque lo mismo), de tal forma que el _desbalance_ sea el menor posible. El _desbalance_ se define como la cantidad total movida entre el monto inicial contra el actual del alumno. Por ejemplo, si un alumno recibía 5 y se le sube a 10, hay un desbalance de $10 - 5 = 5$. De igual forma, si un alumno recibía 20 y se le baja a 10, hay un desbalance de $20 - 10 = 10$. Sea $X$ el monto que le queremos dar a todos los alumnos, entonces el desbalance total es 

$$
\sum_{i = 1}^N |a_i - X|.
$$

Tu tarea es averiguar el menor desbalance para hacer todos los montos iguales.

# Entrada

Se te dará un número $1 \leq N \leq 5 \times 10^5$ indicando la cantidad de alumnos que reciben un apoyo y los montos iniciales $1 \leq a_i \leq 10^6$.

# Salida

Deberás imprimir el menor desbalance posible para hacer todos los montos iguales.

# Ejemplos

||input
4
5 9 5 9
||output
8
||description
Podemos hacer todos los elementos iguales a $7$, y eso tiene un desbalance total de $|5 - 7| + |9 - 7| + |5 - 7| + |9 - 7| = 2 + 2 + 2 + 2 = 8$.
||input
3
1 1 100
||output
99
||input
3
100 100 1
||output
99
||end