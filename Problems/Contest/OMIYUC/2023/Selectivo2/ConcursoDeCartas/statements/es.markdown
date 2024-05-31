# Historia

Todos conocen el famoso juego de **21 BlackJack**, en el que intentas obtener cartas que sumen 21 sin pasarte de ese número. Santy, en su fiesta, decidió jugar una modificación de este juego llamada **$\pi$ BlackJack**. Es básicamente una versión nerd del juego.

En este juego, se utiliza una baraja con cartas numeradas desde el $1$ hasta el $K$, y el objetivo es obtener una mano que sume $N$. Las reglas del juego son las siguientes:

1. Comienzas el juego con una carta de valor $1$.
2. La última carta que pediste debe tener el mismo valor que la carta anterior.
3. Si en tu turno anterior obtuviste una carta de valor $a$, puedes pedir una carta con valor $a + 1$, $a$, o $a - 1$ en el siguiente turno (siempre y cuando te mantengas dentro del rango de cartas disponibles).
4. El primer jugador que alcance la suma de $N$ gana. Si te pasas de $N$, pierdes.

# Problema

Jorge, un amigo aleatorio de Santy que es muy competitivo en juegos como este, te ha pedido que le hagas un programa que pueda indicarle una secuencia óptima de jugadas para ganar en la menor cantidad de turnos posibles.

# Entrada

Se te proporcionarán los números $N$ y $K$, que indican la puntuación a alcanzar y el rango de los valores de las cartas, respectivamente.

# Salida

Debes imprimir una cadena de letras, en la que la letra en la posición $i$ indica la acción que debes tomar en ese turno. Las letras son las siguientes:

- **S**: (Subir) Pide la carta de mayor valor que tenías anteriormente.
- **B**: (Bajar) Pide la carta de menor valor que tenías anteriormente.
- **I**: (Igualar) Pide la carta con el mismo valor que tenías anteriormente.

Puede haber más de una respuesta válida. Cualquier respuesta que cumpla con las reglas del juego será aceptable.

# Ejemplos

||input
5 2
||output
ISB
||description
Primero tienes una carta de valor $1$, luego la igualas para obtener una carta de valor $1$, luego subes para obtener una carta de valor $2$ y, finalmente, bajas para obtener una carta de valor $1$. Al final, tienes un total de $5$ puntos.
Esta es la forma más rápida de ganar. La respuesta "SI" no es válida debido a las reglas del juego.
||input
10 1
||output
IIIIIIIII
||end

# Limites

- $2 \leq N \leq 10^{12}$
- $1 \leq K \leq 10^{12}$
- Se garantiza que la longitud de la salida no superará los $10^6$ caracteres.

**Para un 20% de los casos**

- $1 \leq K \leq 10$
- $2 \leq N \leq 100$

**Para un 20% de los casos**

- $1 \leq K \leq 10^4$
- $2 \leq N \leq 10^4$

**Para un 20% de los casos**

- $1 \leq K \leq 10^8$.
- $2 \leq N \leq 10^8$.

**Para un 20% de los casos**

- $N \leq K$.