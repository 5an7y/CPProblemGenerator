# Problema

Al inicio cuentas con un conjunto vacío $A$. Se te darán únicamente $Q$ instrucciones que deberás realizar en el conjunto. Las operaciones por realizar únicamente pueden ser de dos tipos:

1- Se te dará un numero $x$ y deberás ingresar a $x$ en el conjunto $A$.
2- Se te dará un numero $x$ y deberás verificar si el elemento $x$ se encuentra en $A$.

# Entrada

Un numero $Q$ indicando la cantidad de operaciones a realizar. En las siguientes $Q$ líneas se te darán dos enteros $o, x$ indicando el tipo de operación a realizar y el numero $x$.

# Salida

Para cada operación del tipo dos deberás imprimir "Si" en caso de que el número se encuentre en el conjunto en dicho momento o "No" de caso contrario.

# Ejemplos

||input
6
1 7
1 3
2 2
2 3
1 2
2 2
||output
No
Si
Si
||end

# Limites

- Se te asegura que las intersecciones se te darán de tal forma, que si haces un árbol binario sin balancear, este resultara con altura menor a $log(Q) + 1$.
- $1 \leq Q \leq 10^6$.
- $1 \leq o \leq 2$.
- $1 \leq x \leq 10^9$.

**Para un 20% de los casos**

- $1 \leq Q \leq 1000$.

**Para un 30% de los casos**

- $o_i \leq o_{i+1}$.

**Para un 30% de los casos**

- $1\leq x \leq 10^6$.