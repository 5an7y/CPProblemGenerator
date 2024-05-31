# Historia

Battleship es un juego de mesa bastante famoso entre las personas. Es un juego diseñado para dos jugadores en el cual cada uno cuenta con un tablero secreto (el otro jugador no lo sabe) en donde distribuyen sus barcos alrededor. En cada turno, un jugador decide destruir un espacio del tablero y el primero en destruir todos los barcos gana.

Especialmente a Juanito le ha estado interesando mucho este juego, lo único que no le gusta es la gran aleatoriedad que existe en el juego. Uno puede tener muy mala suerte con sus tiros y no acertar a los barcos. Por esta razón, Juanito ha decidido hacer su variante del juego llamada "FindShip".

En esta variante, cada jugador cuenta con un único barco de $1 \times 1$; es decir, el barco está en una posición del tablero. El tablero tiene un solo número (diferente en cada tablero) para cada posición del mismo. Puedes ver esto como una matriz. Algo peculiar de este tablero es que los números van en aumento tanto en las filas como en las columnas. Entonces, el rival sabe el número de la posición de tu barco, pero no sabe qué números hay en el tablero. En cada turno, el oponente elige una posición y puede saber el número que se encuentra en dicha casilla.

# Problema

Este problema es interactivo. Por lo tanto, tendrás que implementar las funciones descritas en la siguiente sección. Tienes una matriz desconocida de tamaño $N \times M$. Puedes usar la función `Conocer(x, y)` para saber el valor de la matriz en la posición $(x, y)$. Una vez encontrada la posición correcta, tu función deberá terminar.

# Implementación

Debes enviar un archivo que implemente la función `EncontrarNave(int N, int M, int X)`. Esta función podrá llamar a la función `Conocer(int x, int y)` hasta $N \times M$ veces.

## Función del evaluador `Conocer()`

* C/C++ `int Conocer(int x, int y);`

### Descripción

El evaluador proporcionará esta función, la cual te permite saber el valor del elemento en la posición $(x, y)$. La matriz está indexada en cero; en caso de salirse de los límites, la función devolverá un $-1$.

### Parámetros

* `x`: La fila correspondiente por la que se pregunta.
* `y`: La columna correspondiente por la que se pregunta.
* Retorna: un entero indicando el valor de la matriz en esa posición.

## Función que debes implementar: `EncontrarNave()`

* C/C++ `void EncontrarNave(int N, int M, int X);`

### Descripción

La función deberá llamar a `Conocer` hasta encontrar la casilla con valor $X$.

### Parámetros

* `N`: La cantidad de filas de la matriz.
* `M`: La cantidad de columnas de la matriz.
* `X`: El elemento que se está buscando.
* Retorna: Nada.

# Muestra

El archivo consta de tres números en la primera línea: $N, M$ y $X$. A continuación, se debe proporcionar una matriz de $N \times M$ que indique el tablero.

# Ejemplo

||entrada
Encontrar(5, 5, 9)
||salida
||descripción
Se llama a la función que deberá resolver el problema.
||entrada
Conocer(2, 2)
||salida
8
||descripción
Esto nos dice que la matriz en la posición (2, 2) tiene el valor 8.
||entrada
Conocer(3, 2)
||salida
10
||entrada
Conocer(2, 3)
||salida
9
||descripción
Has encontrado el número y deberás terminar el programa.
||fin

# Límites

* $10 \leq N, M \leq 300$
* $1 \leq X \leq 10^6$.

# Evaluación

- **Para el 30% de los puntos**: Puedes llamar a la función encontrar a lo sumo $N \times M$ veces.

- **Para el 60% de los puntos**: Puedes llamar a la función encontrar a lo sumo $\min(N \times \log(M), M \times \log(N))$ veces.

- **Para el 100% de los puntos**: Puedes llamar a la función encontrar a lo sumo $N + M$ veces.

# Experimentación

{{libinteractive:download}}