# Historia

Santy está organizando una fiesta porque su cumpleaños está muy cerca. ¡La fiesta es muy exclusiva y solo pueden asistir un máximo de $K$ personas! Por desgracia, siempre hay personas que no pueden asistir a su fiesta. Ayuda a Santy a determinar quiénes irán a su fiesta de cumpleaños.

# Problema

Santy cuenta con una cantidad $N$ ($>0$ es una persona muy sociable) de amigos en total. Cada amigo puede ser identificado con un id distinto $a_i$. Se te dará una lista de amigos ordenada por preferencia de Santy. Es decir, las primeras personas serán las que a Santy le gustaría que fueran las primeras en ser invitadas.

Luego, se te dará un número $M$ y una lista de personas que no podrán asistir a su fiesta (porque tienen un compromiso o simplemente no les cae tan bien Santy :( ). Dada la cantidad máxima de personas que puede tener Santy en su fiesta, $K$, deberás determinar quiénes irán.

# Entrada

Los enteros $N$, $M$ y $K$ indican la cantidad de amigos de Santy, la cantidad de personas que no pueden asistir y la cantidad máxima de invitados en su fiesta.

En la siguiente línea, se presenta una lista de $N$ números distintos $a_i$, que indica los amigos de Santy en orden de preferencia.

En la última línea, se presenta una lista de $M$ números distintos $b_i$, que indica los amigos que no podrán asistir.

# Salida

Una lista de números que indica los amigos que asistirán a la fiesta en el orden de preferencia de Santy. Imprimir $-1$ si nadie será invitado.

# Ejemplos

||input
5 2 2
8 4 2 1 3
4 1
||output
8 2
||description
Los dos amigos que a Santy le gustaría invitar son $8$ y $4$, pero $4$ no puede asistir, así que Santy invita a $8$ y $2$.
||input
5 3 3
8 4 2 1 3
2 4 1
||output
8 3
||input
9 9 9
1 2 3 4 5 6 7 8 9
9 8 7 6 5 4 3 2 1
||output
-1
||end

# Limites

- $0 < M \leq N \leq 4 \times 10^5$
- $0 < K \leq 3 \times 10^5$
- $0 \leq a_i \leq 10^8$
- Los números de la lista de personas que no pueden asistir siempre serán números de la lista de amigos de Santy.
- Ambas listas contienen elementos distintos.

**Para un 10% de los casos**

- $N = M$.

**Para un 25% de los casos**

- $0 < N \leq 10^4$

**Para un 25% de los casos**

- $a_i \leq 10^6$

**Para un 20% de los casos**

- $a_i < a_{i+1}$
- $b_i < b_{i+1}$