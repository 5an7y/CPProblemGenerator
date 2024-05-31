# Problema

Dentro de la zona de Yucatán se tienen las frecuencias desde la 340 hasta la 1850, las radios han comprado ciertas frecuencias para sus programas de la siguiente forma:

- KarelRadio 420Hz
- OMI-Itza 661Hz
- Las locuras de 5an7y 854Hz
- UniverisiRadio 1111Hz
- UnDiaAdoradoenYucatan(UADY) 1360Hz
- ExaFM 1519Hz

Quieres crear un programa que sea capaz de determinar hacia dónde te tienes que mover para encontrar la estación más cercana.

# Entrada

Se te dará un entero $1 \leq X \leq 2000$ que es la frecuencia en la que te encuentras actualmente.

# Salida

Si la estación más cercana se encuentra adelante deberás imprimir "Adelante" seguido del número de frecuencias que debes avanzar para la siguiente estación. Si la estación más cercana se encuentra atrás, imprime "Atras" seguido del número de frecuencias que debes avanzar para la siguiente estación. Si te encuentras fuera de las frecuencias permitidas deberás imprimir "Sin Servicio". Si ya te encuentras en una estación, imprime únicamente 0.

# Ejemplos

||input
340
||output
Adelante 80
||description
La estación más cercana es la de KarelRadio que se encuentra a 80 frecuencias por delante.
||input
667
||output
Atras 6
||input
1111
||output
0
||input
1900
||output
Sin Servicio
||end