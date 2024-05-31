# Problema

Se te proporcionarán dos enteros positivos $a$ y $b$. Mientras $b$ sea mayor o igual que $a$, deberás restarle $a$ a $b$. Deberás mostrar el valor final de $b$.

# Entrada

Los dos enteros $a$ y $b$ separados por un espacio.

# Salida

Deberás imprimir el valor final de $b$.

# Ejemplos

||input
7 32
||output
4
||description
$32$ es mayor que $7$. Entonces, al valor $32$ le restamos $7$ y nos queda $32 - 7 = 25$. $25$ sigue siendo mayor a $7$; entonces, restamos $25 - 7 = 18$. $18$ sigue siendo mayor a $7$; entonces, restamos $18 - 7 = 11$. Finalmente, $11$ sigue siendo mayor a $7$; entonces, restamos $11 - 7 = 4$ y ya nos queda un valor menor a $7$, que es nuestra respuesta.
||input
19 15
||output
15
||input
5 15
||output
0
||end

# Límites

**Para un 50% de los casos agrupados**

- $1 \leq a, b \leq 10^6$.

**Para un 50% de los casos agrupados**

- $1 \leq a, b \leq 10^{15}$.