# Problema

El Instituto Central del Pensamiento Creativo no es la universidad más seria de todas, por así decirlo. Un ejemplo de esto es su sistema bibliotecario; toda la universidad se rehúsa a ordenar los libros alfabéticamente, porque eso es muy aburrido. Sin embargo, a falta de creatividad, los libros no se encuentran ordenados de alguna forma especial.

Santy ha decidido arreglar esto durante su mandato. Se le ha ocurrido una forma un tanto curiosa de ordenar _algunos_ de los libros. Él quiere formar una línea de libros de tal forma que si tomamos la inicial de cada libro, esta línea forme un palíndromo*. Como quiere ordenar la mayor cantidad de libros posibles, quiere la línea más larga que se pueda. Además de esto, para hacerlo aún más interesante, dentro de todas las opciones iguales quiere la menor lexicográficamente*.

- ***Palíndromo**: Un palíndromo es una palabra que se lee de la misma forma de derecha a izquierda que de izquierda a derecha. Por ejemplo, aérea, ana, salas, rodador.
- ***Lexicográficamente**: Se dice que una palabra es menor a otra lexicográficamente si el primer caracter donde difieren es menor (va primero en el alfabeto) en la primera palabra. Por ejemplo, amancio es menor que amando porque el primer caracter donde difieren es donde uno es c y el otro d, donde la c viene primero en el alfabeto. Más aún, el prefijo de una palabra siempre será menor lexicográficamente. Por ejemplo, auto es menor que automático.

# Entrada

Se te dará una cadena de caracteres $S$ de letras mayúsculas del alfabeto inglés que representan las iniciales de los libros que hay actualmente. La cadena tiene a lo más $5000$ caracteres.

# Salida

Deberás imprimir la cadena que te pide el problema.

# Ejemplos

||input
AAAABBBB
||output
AABBBBAA
||description
Nota que la cadena es un palíndromo. Igual podríamos formar la cadena AAAA pero esta no es la más grande. Por otro lado, igual podríamos formar ABABBABA pero no es la menor lexicográficamente.
||input
ABCDEF
||output
A
||input
ABBAED
||output
ABDBA
||end