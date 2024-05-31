# Problema

Como sabemos los aeropuetos de las ciudades grandes suelen tener problemas de trafico, muchas veces por eso se retrasan ciertos vuelos. Sabemos que cada avion cuenta con un tiempo de llegada $a_i$ y un tiempo de salida $b_i$. Tu tarea sera determinas cuantas autopistas minimo se necesitan para que no haya demora en los vuelos.

Ten encuenta que una autopista se encuentra ocupada por el avion desde que entra hasta que sale, por lo que ningun otro avion puede ocupar su lugar en ese lapso de tiempo.

# Entrada

Se te dara un numero $N$ indicando la cantidad de aviones. Seguido se te daran $N$ parejas de numeros $(a_i, b_i)$ indicando el tiempo de llegada y salida de cada avion.

# Salida

Un unico entero representando el numero minimo de autopistas para que no haya trafico aereo.

# Ejemplos

||input
3
1 2
1 2
2 3
||output
3
||input
4
1 4
5 6
4 10
3 4
||output
3
||input
3
1 2
4 6
3 5
||output
2
||end

# Limites

- $1 \leq N \leq 10^5$
- $1 \leq a_i < b_i \leq 10^8$

**Para un grupo de 20% de los casos**

- $1 \leq N \leq 10^4$
- $1 \leq a_i < b_i \leq 10^3$

**Para un grupo de 20% de los casos**

- $1 \leq N \leq 10^4$
- $1 \leq a_i < b_i \leq 10^8$

**Para un grupo de 20% de los casos**

- $1 \leq N \leq 10^5$
- $1 \leq a_i < b_i \leq 10^6$