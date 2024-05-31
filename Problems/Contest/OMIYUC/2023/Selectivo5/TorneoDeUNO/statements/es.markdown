# Historia

¿No sabías que existía el UNO competitivo? Nosotros tampoco. Las personas han quedado tan agotadas de juegos de mesa complicados que han decidido jugar al famoso juego UNO. Sin embargo, a aquellos que están realmente metidos en los juegos de mesa les encanta competir en todo. Por esta razón, han organizado un torneo de UNO. Este torneo involucra a un total de $2^{N}$ personas, las cuales podemos indexar con números del $1$ al $N$.

En la primera fase, el jugador $1$ se enfrenta al $2$, el $3$ al $4$, y así sucesivamente. En la siguiente fase, el ganador entre el $1$ y el $2$ se enfrenta al ganador entre el $3$ y el $4$. Este proceso se repite hasta que quede un único ganador. La cantidad de enfrentamientos que gane un jugador determina cuán lejos llegó en el torneo.

Lamentablemente, te has perdido el torneo y no sabes quién es el ganador. Sin embargo, lo que puedes hacer es juntar a dos jugadores y preguntarles quién de ellos llegó más lejos en el torneo. Con esta pregunta a tu disposición, podrás determinar quién es el ganador del torneo.

# Problema

Este problema es interactivo. Por lo tanto, tendrás que implementar las funciones descritas en la siguiente sección. Tu tarea es encontrar al ganador del torneo. Puedes usar la función `Mejor(x, y)` para averiguar quién llegó más lejos de los dos participantes.

# Implementación

Debes enviar un archivo que implemente la función `EncontrarGanador(int N)`. Esta función podrá llamar a la función `Mejor(int x, int y)` hasta $2^N$ veces.

## Función del evaluador `Mejor()`

* C/C++ `int Mejor(int x, int y);`

### Descripción

El evaluador proporcionará esta función, la cual te permite saber quién de los dos llegó más lejos. La función devolverá un valor dependiendo de quién fue el que llegó más lejos (ver la sección de parámetros).

### Parámetros

* `x`: Un participante del torneo.
* `y`: Otro participante del torneo.
* Retorna: un entero indicando quién llegó más lejos: $0$ en caso de empate, $1$ en caso de que el primer participante llegó más lejos, y $2$ en caso de que el segundo fue quien llegó más lejos.

## Función que debes implementar: `EncontrarGanador()`

* C/C++ `int EncontrarGanador(int N);`

### Descripción

La función deberá encontrar al ganador del torneo.

### Parámetros

* `N`: Un entero que te indica la proporción de participantes.
* Retorna: Un único entero representando el ganador del torneo.

# Muestra

El archivo consta de un entero $N$ en la primera línea. A continuación, hay $2^N$ enteros que indican la cantidad de juegos ganados por cada jugador.

# Ejemplo

||input
Encontrar(3)
||output
||description
Se llama a la función que deberá resolver el problema.
||input
Mejor(1, 2)
||output
2
||description
Un resultado de 2 indica que el segundo número pasado ha ganado más que el primero. Por lo tanto, sabemos que el jugador 2 fue el ganador de la pelea entre el jugador 1 y el jugador 2.
||input
Mejor(2, 4)
||output
1
||input
Mejor(2, 7)
||output
2
||input
return 7;
||output
||end

# Límites

* $1 \leq N \leq 17$

# Evaluación

- **Para el 40% de los puntos**: Puedes llamar a la función encontrar un máximo de $2^{N}$ veces.

- **Para el 100% de los puntos**: Puedes llamar a la función `Ganador` un máximo de $\lceil \frac{1}{3} \cdot 2^{N + 1} \rceil$.

# Experimentación

{{libinteractive:download}}
