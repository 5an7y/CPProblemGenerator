# Problema

Todos conocen la famosa sucesión de Fibonacci donde cada elemento de la sucesión es la suma de los elementos anteriores. Un amigo llegó y te dijo: "¿Sabías que si tomas dos dígitos y haces una sucesión de dígitos con la suma de los dos anteriores eventualmente llegas al mismo punto?".

Como buen programador, decidiste implementar un código que muestre esto. Se te darán dos dígitos $A, B$ y formarás una sucesión donde cada elemento es **el dígito** de los dos anteriores. Deberás imprimir la sucesión hasta encontrar los dígitos iniciales nuevamente.

# Entrada

Dos dígitos $0 \leq A, B \leq 9$ que son los elementos iniciales de la sucesión.

# Salida

La sucesión completa hasta encontrar de nuevo los elementos iniciales.

# Ejemplos

||input
1 8
||output
1 8 9 7 6 3 9 2 1 3 4 7 1 8
||description
- 1 + 8 = 9
- 8 + 9 = 17 (tomamos el dígito 7)
- 9 + 7 = 16 (tomamos el dígito 6)
- 7 + 6 = 13 (tomamos el dígito 3)
...
||input
8 9
||output
8 9 7 6 3 9 2 1 3 4 7 1 8 9
||end