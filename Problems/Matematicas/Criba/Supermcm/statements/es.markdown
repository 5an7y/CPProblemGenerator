# Problema

Se te dara una lista de $N$ numeros y deberas computar el minimo comun multiplo de todos los numeros. Como las respuesta puede ser muy grande, muestrala modulo $10^9 + 7$.

# Entrada

Se te dara un numero $N$ indicando la cantidad de numeros. En la siguiente linea los elementos de la lista $a_i$.

# Salida

Deberas imprimir el mcm de todos los numeros en la lista modulo $10^9 + 7$.

# Ejemplos

||input
3
10 15 27
||output
270
||description
El minimo comun multiplo de los 3 numeros es $270$.
||input
5
1 2 3 4 5
||output
60
||end

# Limites

- $0 \leq N \leq 10^5$.
- $1 \leq a_i \leq 10^6$.

**Subtarea 1 [20 puntos]**

- $1 \leq a_i \leq 10$.

**Subtarea 2 [30 puntos]**

- Todos los elementos son primos.

**Subtarea 3 [50 puntos]**

- No hay restricciones adicionales