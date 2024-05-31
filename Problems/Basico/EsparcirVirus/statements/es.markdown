# Problema

¡Oh no! Parece que un virus nuevo ha atacado la ciudad y se esparce rápidamente. La ciudad actual se puede ver como una cuadrícula de $N \times M$ zonas. Cada zona se puede encontrar infectada o no. Todas las zonas infectadas esparcen su virus a las zonas adyacentes (arriba, abajo, derecha e izquierda) el siguiente día.

Para poder tener un plan de contingencia, tú conoces la ciudad actualmente y quieres poder predecir cómo estará el día siguiente.

# Entrada

Se te darán dos enteros $1 \leq N, M \leq 15$ que son las dimensiones del mapa.

En las siguientes líneas se te darán $N \times M$ enteros $a_{ij} = 0, 1$. Donde si es igual a $1$ indica que es una zona infectada y $0$ de caso contrario.

# Salida

Deberás imprimir cómo estaría el mapa al día siguiente.

# Ejemplos

||input
3 3 
0 0 0
0 1 0
0 0 0
||output
0 1 0
1 1 1
0 1 0
||input
3 3
1 0 0
0 0 0
0 0 1
||output
1 1 0
1 0 1
0 1 1
||end