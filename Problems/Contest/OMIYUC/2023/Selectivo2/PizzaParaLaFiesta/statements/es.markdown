# Historia

La fiesta parece estar llegando a su fin, y es el momento perfecto para que Santy ponga en marcha su plan secreto. Solo quedan $N$ personas en la fiesta, y Santy planea preparar una **Pizza Suprema** que contiene exactamente $K$ ingredientes diferentes. Santy tiene a su disposición $M$ ingredientes distintos en su casa, lo que significa que hay muchas formas en las que puede hacer la pizza suprema.

Sin embargo, los amigos de Santy tienen preferencias y no están dispuestos a comer la pizza si contiene ciertos ingredientes. En particular, la persona $j$ tiene una lista de $t_j$ ingredientes que no quiere comer, denominados $a_{i,j}$. Santy quiere saber cuál es la máxima cantidad de amigos que podrían comer la pizza si optimiza los ingredientes que utiliza.

# Problema

Tienes $M$ ingredientes que puedes utilizar para crear una pizza, y cada ingrediente está identificado con un número único $p_i$. Además, tienes $N$ amigos, y cada amigo tiene una lista $a_i$ de ingredientes que **no quiere** en la pizza.

Tu tarea es determinar cuál es la cantidad máxima de amigos que les gustaría comer la pizza si la tienes que hacer con $K$ ingredientes.

# Entrada

Se te dará un número $M$ que indica la cantidad de ingredientes disponibles, un número $N$ que indica la cantidad de amigos, y un número $K$ que representa la cantidad de ingredientes que debe tener la pizza.

En la siguiente línea, se te darán $M$ números $p_i$ que representan los ingredientes disponibles.

En las siguientes $N$ líneas, se te dará la lista de ingredientes que cada amigo no quiere en la pizza. Cada línea comienza con un entero $t_i$ que indica la cantidad de ingredientes que no desea la persona $i$. Luego, se proporcionan los $t_i$ números que representan los ingredientes que no desea esa persona.

# Salida

Un único número entero que indica la cantidad máxima de amigos que estarían interesados en comer la pizza si se construye de forma óptima.

# Ejemplos

||input
5 3 3
9 4 1 3 2
2 1 2
2 2 3
1 1
||output
2
||description
Podemos elegir los ingredientes $9, 4$ y $3$. De esta forma, tanto el primer como el último amigo estarían interesados en comer la pizza, por lo que la respuesta es 2.
||input
4 3 2
1 2 3 4
2 4 2
1 2
||output
1
||end

# Limites

- $1 \leq K \leq N \leq 50$.
- $1 \leq M \leq 20$.
- La lista de los amigos siempre son ingredientes distintos y que estan presentes en la lista original.

**Para un 20% de los casos**

- $N, M \leq 10$.

**Para un 30% de los casos**

- $N \leq 20$.