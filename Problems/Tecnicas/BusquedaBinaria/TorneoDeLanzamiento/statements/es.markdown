La Organización Mecánica Innovadora en Yucatán (La OMIYUC) está organizando su torneo anual de lanzamiento de objetos. Todo el mundo se reúne para ver cómo la gente lanza objetos aleatorios a una distancia muy lejana. En esta edición se cuenta con un total de $N$ competidores y $M$ objetos a ser lanzados. Cada competidor lanzará cada uno de los objetos.

La distancia que alcanza un objeto lanzado por una persona está determinada por 3 factores principales: $f$ la fuerza de la persona, $a$ la altura de la persona y $p$ el peso del objeto lanzado. La distancia que se alcanza en un tiro es:

$$
d = \frac{f \cdot a}{p}.
$$

La calidad de una competición está determinada por la cantidad de lanzamientos que logren pasar por lo menos una distancia $D$.

# Problema

Se te dará la lista de competidores y de objetos. Tu tarea será determinar la calidad de la competición actual, teniendo en cuenta que todos los competidores lanzan todos los objetos.

# Entrada

Se te darán tres enteros en la primera línea $N$, $M$ y $D$ representando la cantidad de competidores, la cantidad de objetos y la distancia que determina la calidad de la competición.

Luego se te darán $N$ pares $(f_i, a_i)$ que representan la fuerza y la altura del $i$-ésimo participante.

Seguido se te dará una lista de $M$ enteros $p_i$ que representan los pesos de los objetos.

# Salida

Deberás imprimir un entero representando la calidad de la competición.

# Ejemplos

||input
4 3 14
4 14
3 10
5 11
29 5
4
10
7
||output
4
||description
Hay 4 configuraciones que logran alcanzar la distancia de 14.

1. La primera persona (fuerza 4, altura 14) con el primer objeto (peso 4) $\frac{14 \cdot 4}{4} = 14$.

2. La cuarta persona (fuerza 29, altura 5) con el primer objeto (peso 4) $\frac{29 \cdot 5}{4} = 36.25$

3. La cuarta persona (fuerza 29, altura 5) con el segundo objeto (peso 10) $\frac{5 \cdot 29}{10} = 14.5$

4. La cuarta persona (fuerza 29, altura 5) con el tercer objeto (peso 7) $\frac{5 \cdot 29}{7} = 20.71$
||end

# Límites

- $1 \leq N, M \leq 10^5$
- $1 \leq D, f_i, a_i, p_i \leq 10^9$
- Todas las subtareas se encuentran agrupadas.

**Subtarea 1 [7 puntos]**

- $N = 1, M = 1$

**Subtarea 2 [9 puntos]**

- $N = 1$

**Subtarea 3 [9 puntos]**

- $M = 1$

**Subtarea 4 [10 puntos]**

- $1 \leq N, M \leq 10^3$

**Subtarea 5 [15 puntos]**

- $p_i = 1$ para toda $i$.

**Subtarea 6 [50 puntos]**

- No hay restricciones adicionales.