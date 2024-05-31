# Problema

¿Sabes lo malo de tener una empresa diversa? La comunicacion. Una empresa muy diversa cuenta con $N$ empleados, en conjunto todos hablan un total de $M$ lenguas distintas. Para simplificar las cosas las lenguas las podemos numerar del $1$ al $M$. Una persona se puede comunicar con otra si saben la misma lengua o si pueden usar la ayuda de mas personas para hacer traducciones.

No obstante, puede que suceda que una persona no pueda comunicarse con otra, lo cual es un gran problema. Es por eso que la empresa a decidio enseñarle lenguas a sus empleados. Sin embargo, esto tiene un alto costo, hacer que una persona aprenda una lengua tiene un costo de $1$ peluche dolar. Ayuda a la empresa a saber cuanto es lo minimo que debe gastar para que todos se puedan comunicar entre si.

# Entrada

Se te dara un numero $N$ indicando la cantidad de empleados y un numero $M$ indicando la cantidad de lenguas habladas en la empresa.

En la siguientes $N$ lineas se te dara $k_i$ indicando la cantidad de lenguas que habla una persona (posiblemente 0 si la lengua es muy muy rara y nadie mas la puede si quiera aprender) y seguido $k_i$ numeros $a_{i, j}$ que indican las lenguas habladas por la $i$-esima persona.

# Salida

Un entero indicando la cantidad minima de peluche dolares que la empresa debe gastar.

# Ejemplos

||input
5 5
1 2
2 2 3
2 3 4
2 4 5
1 5
||output
0
||input
8 7
0
3 1 2 3
1 1
2 5 4
2 6 7
1 3
2 7 4
1 1
||output
2
||input
2 2
1 2
0
||output
1
||end

# Limites

- $1 \leq N, M \leq 1000$
- $0 \leq k_i \leq M$
- $1 \leq a_{i, j} \leq M$. Todos distintos para una lista.

**Para un 20% de los casos**

- $M = 1$.

**Para un 20% de los casos**

- $k_i = 1$.