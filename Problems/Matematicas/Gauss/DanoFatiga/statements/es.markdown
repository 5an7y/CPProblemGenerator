# Problema

A Santy le encanta jugar Hearthstone, un juego estratégico de cartas (similar a Magic). En este juego, cuentas con un mazo de 30 cartas, y una vez que se agotan, comienzas a sufrir daño por fatiga. El daño por fatiga funciona de la siguiente manera: *la primera vez que intentas robar una carta, recibes 1 punto de daño, y cada vez que intentas robar una carta adicional, el daño aumenta en 1 con respecto al intento anterior*. Es importante señalar que, por defecto, siempre intentas robar una carta al comienzo del turno.

Santy se encuentra en una situación interesante. Es el turno de Santy, ha agotado su mazo y no le quedan más cartas, excepto una carta mágica que cambia la forma en que **su oponente** (Ramon) roba cartas al inicio de su turno. Ahora, su oponente intentará robar una carta al inicio de su próximo turno y, en cada turno subsiguiente, intentará robar una carta adicional más que en el turno anterior. Sin embargo, el oponente de Santy cuenta con un *minion* que inflige un daño fijo de $X$ a Santy cada turno. Dado que Santy no quiere perder tiempo, te ha pedido que determines quién ganará al final. La persona pierde tan pronto como su vida llega a $0$ o menos.

# Entrada

Se te proporcionarán los números $N$, $M$ y $X$, que representan la vida de Santy, la vida de su oponente y el daño del *minion* del oponente.

# Salida

Deberás imprimir "Santy" si él gana o "Ramon" si él gana.

# Ejemplos

||input
12 13 2 
||output
Santy
||description
- Primer turno de Ramon: Toma $1$ de daño de fatiga y le hace $2$ de daño a Santy.
- Primer turno de Santy: Toma $1$ de daño de fatiga. Ramon tiene $12$ de vida y Santy $10$.
- Segundo turno de Ramon: Toma $2$ y $3$ de daño de fatiga y le hace $2$ de daño a Santy. Ramon tiene $7$ de vida y Santy $8$.
- Segundo turno de Santy: Toma $2$ de daño de fatiga. Ramon tiene $7$ de vida y Santy $6$.
- Tercer turno de Ramon: Toma $4$, $5$ y $6$ de daño de fatiga y su vida baja por debajo de $0$, entonces pierde.
||input
100 20 4
||output
Ramon
||input
10 40 20
||output
Ramon
||end

# Limites

**Para un 20% de los casos agrupados**

- $1 \leq N, M, X \leq 10^6$.

**Para un 30% de los casos agrupados**

- $1 \leq N, M, X \leq 10^{16}$.

**Para un 50% de los casos agrupados**

- $1 \leq N, M, X \leq 1.3 \times 10^{19}$.