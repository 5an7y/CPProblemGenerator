# Problema

Se te dará una lista de palabras y deberás imprimir la palabra más frecuente. En caso de existir múltiples soluciones, imprimir la menor lexicográficamente.

# Entrada

Se te dará un numero $N$ indicando la cantidad de palabras. Seguido se te darán $N$ líneas en donde cada uno contendrá una palabra compuesta únicamente de letras del alfabeto ingles en mayúsculas y minúsculas.

# Salida

Imprimir la palabra que se repita más y sea la menor lexicográficamente.

# Ejemplos

||input
5
Ana
Mona
Papa
Ana
Ana
||output
Ana
||input
8
Hola
hola
Arepa
hola
Arepa
Hola
Arepa
Hola
||output
Arepa
||end

# Limites

- La cadena únicamente contiene letras del alfabeto inglés.
- Cada cadena tiene a lo más 800 letras.

**Para un 50% de los casos**

- $1 \leq N \leq 200$.

**Para un 50% de los casos**

- $1 \leq N \leq 5000$.