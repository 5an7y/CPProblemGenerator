# Problema

Como es bien conocido, a los olímpicos les encanta jugar con piedras. Si no lo sabes, tarde o temprano te darás cuenta. Santy, cansado de jugar el típico juego de NIM y todas sus variantes, ha decidido crear su propio juego de piedras e invitó a Yahir para jugar contra él.

El juego consiste en que se tienen $N$ pilas de piedras, cada pila contiene $a_i$ piedras. Santy empieza jugando, él puede tomar una piedra de cualquier pila. A partir de allí, el siguiente jugador toma una piedra *de cualquier pila excepto de la que el jugador anterior acaba de tomar*. Cuando un jugador ya no tiene opciones de piedras para tomar, el juego termina y ese jugador pierde.

Suponiendo que ambos juegan de la mejor forma posible, determina al ganador.

# Entrada

Se te dará un número $N$ indicando la cantidad de pilas, seguido de $N$ enteros $a_i$ indicando la cantidad de piedras en cada pila.

# Salida

Debes imprimir "Santy" en caso de que Santy sea el ganador o "Yahir" en caso contrario.

# Ejemplos

||input
1
10
||output
Santy
||description
Yahir no puede tomar ninguna piedra después de Santy.
||input
2
4 10
||output
Santy
||input
2
1 1
||output
Yahir
||end

# Límites

- Todas las subtareas están agrupadas.

**Para un 20% de los casos:**

- $N = 2$
- $1 \leq a_i \leq 100$.

**Para un 10% de los casos:** 

- $N$ es par
- $2 \leq N \leq 100$.
- $1 \leq a_1 = a_2 = ... = a_N \leq 100$.

**Para un 20% de los casos:** 

- $1 \leq N \leq 100$
- $a_i = 1$.

**Para un 50% de los casos:**

- $1 \leq N \leq 100$
- $1 \leq a_i \leq 100$