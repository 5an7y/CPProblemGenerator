# Problema

Santy se dio cuenta de que la palabra "Fosa", si uno le aplica 2 rotaciones a la izquierda, se convierte en "saFo", que sigue siendo una palabra.

Si tienes una cadena de caracteres $S$, donde los caracteres son $S_i$, aplicar una rotación a la izquierda implica hacer $S_i = S_{i+1}$ para $i < N$ y $S_N = S_1$.

Ahora Santy tiene una cadena $A$ y quiere saber cuántas rotaciones a la izquierda le debe aplicar como mínimo para obtener otra cadena $B$.

# Entrada

Dos cadenas de caracteres compuestas únicamente de letras del alfabeto inglés en mayúsculas. El tamaño de ambas cadenas es menor o igual a $10^5$.

# Salida

Un entero indicando la cantidad mínima de rotaciones a la izquierda que se deben hacer para conseguir la otra cadena.

# Ejemplos

||input
ABCDEF DEFABC
||output
3
||input
ABCABCABC BCABCABCA
||output
1
||end