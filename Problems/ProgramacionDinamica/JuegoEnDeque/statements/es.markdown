# Problema

Despues de resolver el problema **Un Juego** de la IOI de 1996 Jorge y Alonso se propusieron jugarlo. Cuentas con un arreglo de numeros $(a_1, ..., a_n)$ y se toman turnos de la siguiente forma:

- Tomas el elemento del extremo izquierdo o el extremo derecho y se agrega a tu puntacion.
- Se borra el elemento tomado del arreglo.

El juego termina cuanto no quedan elementos del arreglo. Jorge empieza a jugar y digamos que su puntacion es $X$, por otro lado, la puntacion de Alonso es $Y$. Jorge intenta maximizar $X - Y$, mientras que Alonso intenta maximizar $Y - X$. Tu tarea es determinar el puntaje $X - Y$ si ambos juegan de forma optima.

# Entrada

Se te dara un numero $N$ indicando el tamaño del arreglo. En el siguiente linea se te daran los $N$ números que representan los números del arreglo.

# Salida

Deberas imprimir el puntaje $X - Y$ suponiendo que ambos juegan de forma optima.

# Ejemplos

||input
4
10 80 90 30
||output
10
||description
El juego procede de la siguiente forma asumiendo que ambos juegan de forma optima:

- Jorge: $(10, 80, 90, 30) -> (10, 80, 90)$
- Alonso: $(10, 80, 90) -> (10, 80)$
- Jorge: $(10, 80) -> (10)$
- Alonso: $(10) -> ()$

Al final $X = 30 + 80 = 110$ y $Y = 90 + 10 = 100$. $X - Y = 110 - 100 = 10$.
||input
3
10 100 10
||output
-80
||input
1
10
||output
10
||input
10
1000000000 1 1000000000 1 1000000000 1 1000000000 1 1000000000 1
||output
4999999995
||input
6
4 2 9 7 1 5
||output
2
||end

# Limites

- $1 \leq N \leq 5 \times 1000$.
- $1 \leq a_i \leq 10^8$.

**Para un grupo de 20% de los casos**

- $1 \leq N \leq 10$.
- $1 \leq a_i \leq 100$.

**Para un grupo de 20% de los casos**

- $1 \leq N \leq 1000$.
- $1 \leq a_i \leq 1000$.

**Para un grupo de 20% de los casos**

- $1 \leq N \leq 1000$.
- $1 \leq a_i \leq 10^8$.

**Para un grupo de 20% de los casos**

- $1 \leq N \leq 5 \times 1000$.
- $1 \leq a_i \leq 1000$.

**Para un grupo de 20% de los casos**

- No hay restricciones adicionales.