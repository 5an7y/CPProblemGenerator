# Historia

La pizza fue todo un éxito. Sin embargo, esto provocó que personas no deseadas ingresaran a la fiesta. Santy es muy astuto y le asignó un ID a cada persona que invitó. Si hay $N$ personas, uno pensaría que lo lógico es asignar a cada persona un número entre $1$ y $N$. Pero este sistema sería demasiado fácil y alguien podría inventar un número. En cambio, Santy utilizó un sistema en el que asignaba solo números que no fueran palíndromos en su representación binaria. Por ejemplo, el número $13$ en binario es $1101$, que no es un palíndromo. Por otro lado, el número $15$ en binario es $1111$, que sí es un palíndromo y, por lo tanto, no se utiliza. En la fiesta, intentaron engañar a Santy ingresando a personas con números consecutivos, pero no tuvieron en cuenta la astucia del sistema de Santy.

# Problema

Santy pudo observar que en la fiesta están todos los números consecutivos entre $a$ y $b$. Tu tarea será determinar cuántos infiltrados hay **como mínimo**.

# Entrada

Dos enteros $a$ y $b$ que indican el rango de números consecutivos que Santy logró observar.

# Salida

Un único entero que representa la cantidad mínima de infiltrados que hay.

# Ejemplos

||input
8 16
||output
2
||description
Los únicos infiltrados de los que podemos estar seguros son el $9$ y el $15$, que en binario son $1001$ y $1111$ respectivamente.
||input
47 107
||output
8
||end

# Limites

- $0 \leq a \leq b \leq 2^{55}$

**Para un 20% de los casos**

- $0 \leq a \leq b \leq 10^6$.

**Para un 30% de los casos**

- $0 \leq a \leq b \leq 10^8$.

**Para un 30% de los casos**

- $0 \leq a \leq b \leq 2^{30}$.