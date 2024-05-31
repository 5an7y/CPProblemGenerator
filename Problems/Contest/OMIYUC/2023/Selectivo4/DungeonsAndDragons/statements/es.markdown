# Historia

¿A quién no le gusta una buena sesión de Calabozos y Dragones (Dungeons and Dragons en inglés)? Últimamente, Daniel está muy enganchado a sus sesiones con su grupo. Actualmente, se encuentran en una encrucijada donde tienen que salvar a la princesa en un castillo.

El castillo cuenta con $N$ habitaciones que deben recorrer en orden. Al cruzar todas las habitaciones, llegarán a la princesa a la que deben rescatar. En cada habitación, puede haber un dragón o un duende mágico. Lo bueno del equipo de Daniel es que son lo suficientemente fuertes como para derrotar a cualquier dragón que se interponga en su camino. Al vencer a un dragón, obtienes una cierta cantidad $a_i$ de monedas. Tú puedes decidir si derrotarlo o pasar a la siguiente habitación. Todos quieren obtener la mayor cantidad de monedas posible, ¿por qué no derrotar a todos los dragones?

Sin embargo, resulta que cuando llegas a la habitación de un duende mágico, te dice: "Si has derrotado a más de $a_i$ dragones hasta este punto, entonces no puedes continuar con esta misión". Por suerte, conseguiste un mapa del castillo gracias a una misión secundaria. Ahora sabes cómo están distribuidas las habitaciones y los valores que contienen. Quieres saber cuál es la cantidad máxima de oro que puedes obtener al salvar a la princesa.

# Problema

Se te dará una descripción del mapa del castillo. Este se muestra como un arreglo de habitaciones. Cada habitación se indica con los caracteres `D` o `M`, que representan un dragón o un duende mágico, respectivamente.

Debes imprimir un solo número entero que indique cuál es la cantidad máxima de oro que puedes obtener al cumplir la misión de salvar a la princesa.

# Entrada

Se te dará un número $N$ que indica la cantidad de habitaciones.

En la siguiente línea, se te proporcionará una serie de caracteres que contienen el carácter `D` o `M`, representando dragones o duendes mágicos (D & M).

Luego, se te dará una serie de números $a_i$. Si corresponde a un dragón, indicará la cantidad de oro que obtendrás al derrotarlo; en caso de tratarse de un duende, será el límite de dragones hasta ese punto.

# Salida

Deberás imprimir un solo número entero que represente la cantidad máxima de oro que puedes obtener.

# Ejemplos

||input
5
D D M D M
10 42 1 2 3
||output
44
||description
Derrotas al segundo dragón, ya que si vences al primero, de todas formas superas el límite del tercer duende. Finalmente, derrotas al último dragón y obtienes un total de $42 + 2 = 44$ monedas.
||input
6
D M D M D M
4 1 15 1 10 1
||output
15
||end

# Límites

- $N \leq 10^6$.
- $1 \leq a_i \leq 10^6$.

**Para el 10% de los casos**

- No hay duendes.

**Para el 10% de los casos**

- $a_i < a_{i + 1}$.

**Para el 10% de los casos**

- $N \leq 10$.

**Para el 30% de los casos**

- $N \leq 10^3$.

**Para el 30% de los casos**

- No hay restricciones.