# Problema

En México, es muy común seguir usando el efectivo al comprar algo. Uno de los grandes problemas del efectivo es siempre tener el mínimo número de monedas (y billetes) posibles. Un día te dispones a retirar una cantidad $X$ de tu cuenta bancaria y el cajero se encarga de darte el mínimo número de monedas. ¿Cuántas monedas te dio el cajero?

Ten en cuenta que en México se manejan las siguientes denominaciones de monedas (y billetes) de forma común:

$$
[1, 2, 5, 10, 20, 50, 100, 200, 500]
$$

# Entrada

Se te dará un número $X$ que es la cantidad que quieres retirar.

# Salida

Un entero indicando la mínima cantidad de monedas que te pueden dar.

# Ejemplos

||input
425
||output
4
||description
Las 4 monedas son $200 + 200 + 20 + 5 = 425$
||input
8
||output
3
||end

# Límites

- $0 \leq X \leq 10^8$.