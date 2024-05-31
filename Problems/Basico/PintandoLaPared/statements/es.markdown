# Problema

Santy decidio pintar su pared de muchos colores, para esto dividio la pared de forma horizontal en $N$ secciones. Ademas Santy cuenta con $M$ colores de pintura distintos, lamentablemente las cubetas de pintura son de distintos tamaños entonces la pintura $i$ solo puede pintar $a_i$ bloques.

Ademas una buena pared no puede tener colores juntos, en especial, Santy quiere que entre $K$ secciones contiguas no existan colores repetidos. Tu tarea sera determinar si esto es posible.

# Entrada

Se te daran $N$, $M$ y $K$ descritos anteriormente.

Seguido se te daran $M$ numeros $a_i$ que indican las secciones que puede pintar de cada color.

# Salida

Deberas imprimir "Si" en caso de que se pueda pintar la pared con las restricciones mencionadas anteriormente, de caso contrario imprimir "No".

# Ejemplos

||input
12 6 2
1 1 1 1 1 7
||output
No
||input
12 6 2
2 2 2 2 2 2
||output
Si
||end

# Limites

- $1 \leq K \leq N \leq 10^9$.
- $1 \leq M \leq 10^5$.
- $a_1 + ... + a_M = N$.
- Los casos se encuentran agrupados por pares

**Para 30% de los casos**

- $1 \leq N, M \leq 10^4$.

**Para 30% de los casos**

- $1 \leq N \leq 10^6$.