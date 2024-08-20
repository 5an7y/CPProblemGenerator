# Descripción

David se encuentra en medio de la preparación de un regalo muy especial para celebrar el cumpleaños de su querida amiga Lola. Él cuenta con lista de $N$ números y el regalo será la cantidad de dinero igual al producto de todos esos números. Con una sonrisa, David se pregunta cómo puede hacer este regalo aún más grandioso para Lola, pues ella merece lo mejor.

David, le propone lo siguiente: antes de calcular el producto de la lista de números que conforman su regalo, ella puede sumarle 1 a uno de ellos.

¿Qué número debería elegir Lola para obtener la mayor cantidad de dinero posible?
# Entrada

La primera línea contiene un solo entero $N$.

 La segunda línea contiene $N$ enteros separados por espacios $a_i$ que representan la lista de números.

# Salida

Imprime un solo entero, el número que Lola debería elegir para maximizar el dinero.

# Ejemplo

||input
3
5 5 5
||output
5
||description
Como todos los números son iguales, solo podemos elegir el número 5
||input
3
12 10 11
||output
10
||description
Si aumentamos 1 al 12 el resultado es $(12+1)\cdot 10 \cdot 11 =1430$, al 10 es 1452, al 11 es 1440,
por lo tanto, lola debería elegir el número 10.
||end

# Límites

- $2\leq N \leq 10^5$

- $1\leq a_i\leq 10^9$

#Subtareas

**Subtarea 1** (20 puntos)

- $2\leq N\leq 5$

- $1\leq a_i\leq 50$

**Subtarea 2** (20 puntos)

- Todos los números de la lista son iguales

**Subtarea 3** (60 puntos)

- Sin consideraciones adicionales
