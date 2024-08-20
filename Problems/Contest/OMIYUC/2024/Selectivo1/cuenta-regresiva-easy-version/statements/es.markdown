# Descripción

Estás en un laboratorio nuclear que está a punto de explotar y destruir la Tierra. Debes salvar la Tierra antes de que la cuenta regresiva llegue a cero.

La cuenta regresiva consiste en $N$ indicadores mecánicos, cada uno mostrando un dígito decimal. Notaste que cuando la cuenta regresiva cambia su estado de $X$ a $X-1$, no sucede en un solo movimiento. En su lugar, cada cambio de un solo dígito toma un segundo.

Por ejemplo, si la cuenta regresiva muestra 42, entonces cambiará a 41 en un segundo, porque solo un dígito se cambia, pero si la cuenta regresiva muestra 2300, entonces cambiará a 2299 en tres segundos, porque los tres últimos dígitos se cambian.

Descubre cuánto tiempo queda antes de que la cuenta regresiva llegue a cero. Como el número puede ser muy grande, imprime tu respuesta modulo $10^9+7$
# Entrada

La primera línea contiene un solo entero $N$

La segunda línea contiene un número de $N$ dígitos, el estado actual de la cuenta regresiva. Se garantiza que al menos un dígito no es cero.

# Salida

Imprime un solo entero módulo $10^9+7$, el número de segundos restantes antes de que la cuenta regresiva llegue a cero.

# Ejemplo


||input
2
42
||output
46
||description
En el primer ejemplo, hay cuatro cambios que toman 2 segundos: 40 a 39, 30 a 29, 20 a 19, y 10 a 09,
los cambios restantes toman 1 segundo cada uno. Así que el tiempo total es $2 \cdot 4 + 1 \cdot (42 - 4) = 46$.
||input
10
1234567890
||output
371742088
||description
La respuesta para este caso es 1371742095, pero tenemos que aplicar el módulo $10^9+7$ y nos queda $1371742095 \% (10^9+7)=371742088$

||end

# Límites
- $1\leq N \leq 400000$

#Subtareas

 **Subtarea 1** (20 puntos)

- $N=1$

**Subtarea 2** (20 puntos)

- $1 \leq N \leq 5$

**Subtarea 3** (25 puntos)

- $1 \leq N \leq 1000$

**Subtarea 4** (35 puntos)

- sin consideraciones adicionales
