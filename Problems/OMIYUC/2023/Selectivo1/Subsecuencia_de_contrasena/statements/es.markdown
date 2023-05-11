# Historia

Sofia quiere crear una cuenta en la nueva red social *thick toc*. Sin embargo, los sistemas de seguridad de la aplicacion son un poco distintos. Normalmente una pagina te deja poner una contraseña que cumpla ciertos requerimentos. Pero en el caso de esta aplicacion no es asi.

La aplicacion tiene una cadena de caracteres $S$. La contraseña de un usuario debe ser una subsecuencia de esta cadena. Una subsecuencia de la cadena $S$ consiste de elementos de la misma cadena, no necesariamente contiguos, pero el mismo orden de la cadena original. Por ejemplo, si tenemos la cadena $abacaba$ sabemos que $bcba$ es una subsecuencia. Sin embargo, $ababc$ no lo es.

![](Subsecuencia.png)

Sofia no es una persona que sea muy cuidadosa con su seguridad. Es por eso que le encanta poner la misma contraseña en todas partes. Ayudala a determinar si puede poner esa misma contraseña en este sitio.

# Problema

Se te dara una cadena $S$ que es la cadena original que posee la aplicacion. Ademas se te dara una cadena $P$ que es la contraseña que Sofia quiere poner en el sitio. Tu tarea sera determinar si es posible o no poner esa contraseña en la aplicacion.

# Entrada

En la primera linea la cadena $S$ indicando la cadena original del sitio. En la segunda linea una cadena $P$ que es la contraseña que sofia quiere poner.

# Salida

Deberas imprimir "Si" es caso de que sea posible y "No" de caso contrario.

# Ejemplos

||input
abacaba
cba
||output
Si
||input
sortifilia
sofia
||output
Si
||input
pastor
pies
||output
No
||input
abcde
fghij
||output
No
||end

# Limites

Denotaremos $|P|$ al tamaño de cadena $P$.

- $0 < |S|, |P|  \leq 10^6$
- Las cadenas solo contienen letras del alfabeto ingles, numeros y simbolos (no espacios).

**Para un 10% de los casos [Agrupados a pares]**

- $|P| = |S|$.

**Para un 10% de los casos [Agrupados a pares]**

- Todos los caracteres de cada cadena son iguales.

**Para un 20% de los casos [Agrupados a pares]**

- Todos los caracteres de cada cadena son diferentes y ordenadas alfabeticamente.

**Para un 20% de los casos**

- $1 \leq |P|, |S| \leq 10$

**Para un 20% de los casos**

- $100 \leq |P|, |S| \leq 10^4$

**Para un 20% de los casos [Agrupados a pares]**

- No hay restricciones adicionales.