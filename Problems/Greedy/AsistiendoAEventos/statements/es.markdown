# Problema

A Santy le encanta asistir a campamentos de programacion competitiva y charlas acerca de temas relacionados a Inteligencia Artificial. Es año toco el consorcio mas grande de inteligencia artificial justamente en Mexico. Claramente Santy no se lo podia perder. El evento cuenta con un total de $N$ conferencias, cada una iniciando en $I_i$ y terminando en $F_i$.

Lamentablemente la agenda no esta diseñada para que puedas asistir a todas las conferencias, hay algunas que se traslapan. Pero Santy quiere disfrutar del evento al maximo. Para el entre mas conferencias completas asista mejor. Ayudalo a saber el numero maximo de conferencias a las que puede asistir.

Si Santy termina un evento en el tiempo $F_1$ solo puede asistir a otro evento que inice estrictamente **despues** (i.e. $F_1 + 1 \geq$)

# Entrada

Se te dara un numero $N$ indicando la cantidad de conferencias. En las siguentes $N$ lineas se te daran los tiempos de inicio y final de cada conferencia ($I_i$, $F_i$).

# Salida

Deberas imprimir la cantidad maxima de eventos a los que puedes asistir.

# Ejemplos

||input
4
3 10
2 3
5 8
11 20
||output
3
||description
Claramente no podemos asistir a todos los eventos, pero si podemos asistir a los 3 ultimos sin problema.
||input
4
1 4
2 8
3 10
9 15
||output
2
||description
Una posible solucion es ir al segundo y ultimo evento.
||end

# Limites

- $1 \leq N \leq 10^5$
- $1 \leq I_i < F_i \leq 10^6$
- Todas las subtareas se encuentran agrupadas

**Subtarea 1 [15 puntos]**

- $N = 2$.

**Subtarea 2 [15 puntos]**

- $I_{i} = I_{i+1}$.

**Subtarea 3 [20 puntos]**

- $F_{i} \leq I_{i + 1}$.

**Subtarea 4 [20 puntos]**

- $F_{i} - I_{i} = F_{i+1} - I_{i+1}$.

**Subtarea 5 [30 puntos]**

- No hay restricciones adicionales