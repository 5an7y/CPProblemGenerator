# Problema

Harry y Ron se encuentran en la maravillosa escuela de Hogwarts. La escuela cuenta con $N$ cuartos numerados del $1$ al $N$. Ademas existen $M$ pasadisos que conectan a los cuartos de forma especial, si el camino entre dos cuartos $i$ y $j$ existe, entonces dicho camino es unico. Cada cuarto tiene una ventana que puede estar ya sea abierta o cerrada, si dos ventanas abiertas se encuentran conectadas (de alguna forma) entonces hay una corriente de viento pasando entre ellas.

Harry se pregunto: "¿Cuanta parejas de cuartos existen que provoquen una corriente de viento?". Por otro lado, Ron se pregunta "¿Cuantos cuartos hay tal que por lo menos una corriente de viento pase atraves de ellos?".

# Entrada

Se te daran $N$ y $M$ indicando los numeros de cuartos y pasadisos. 

En la siguiente linea se te daran $N$ numeros donde un $1$ indica que la ventana de la habitacion $i$ esta abierta o $0$ de caso contrario.

Finalmente recibiras $M$ parejas de numeros $(a_i, b_i)$ que describen que existe un pasadiso entre las habitacion $a_i$ y $b_i$.

# Salida

Deberas imprimir dos enteros, la respuesta a la pregunta de Harry y la respuesta a Ron.

# Ejemplos

||input
6 5
1 1 1 1 1 0
1 2
1 6
1 5
2 4
4 3
||output
10 5
||input
2 1
1 0
1 2
||output
0 0
||end

# Limites

- $0 \leq M \leq N-1$

**Para un 40% de los casos**

- $1 \leq N \leq 1000$

**Para un 60% de los casos**

- $1 \leq N \leq 5 \times 10^4$