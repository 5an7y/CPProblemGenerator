# Problema

La Universidad, donde Santy gobierna, es tan antigua que muchos la consideran una ruina. Existen partes que ya no tienen ni suelo. Santy, como buen director, ha decidido restaurar el lugar. Un alumno ha hecho un mapa del lugar, por suerte el perímetro de la universidad se encuentra intacto gracias a unas luces colocadas alrededor. Pero por dentro hay huecos que hay que cubrir. Tu tarea consiste únicamente en contar la cantidad de huecos que hay en las ruinas.

El mapa del lugar consiste en una matriz de $N \times M$ que contiene unos y ceros, donde un cero representa una zona vacía y un uno una parte completa de las ruinas. El perímetro de las ruinas se encuentra intacto, por lo que podemos distinguir el área exterior de las partes vacías de las ruinas por el área delimitada por los unos.

# Entrada

Dos enteros $1 \leq N, M \leq 1000$ que representan las dimensiones del mapa. Luego, los elementos $a_{i, j} = 0, 1$ del mapa, donde $0$ representa un lugar fuera de las ruinas o un lugar a restaurar, y un $1$ una zona firme de las ruinas.

# Salida

Deberás imprimir la cantidad de lugares a restaurar dentro de las ruinas.

# Ejemplos

||input
5 5
1 1 1 1 0
1 0 0 1 0
1 1 1 1 1
0 1 0 0 1
0 1 1 1 1
||output
4
||description
El perímetro lo delimitan justo los 1s que forman como dos rectángulos unidos y ambos tienen dos lugares a restaurar.
||input
4 4
1 1 1 1
1 0 0 1
1 0 0 1
1 1 1 1
||output
4
||input
4 7
0 0 0 1 0 0 0
0 0 1 0 1 0 0
0 1 0 1 0 1 0
1 1 1 1 1 1 1
||output
3
||end

# Clarificación

Una zona decimos que NO es parte de las ruinas si es una zona vacía en el borde del mapa o si colinda (arriba, abajo, izquierda o derecha) con otra zona que NO es parte de las ruinas.