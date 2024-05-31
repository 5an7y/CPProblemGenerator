# Historia

Hemos recibido información super secreta de la OMI. Parece ser que a partir de este año cada estado solo puede mandar a $2$ programadores a la competencia nacional. Además, será una competencia por parejas; es decir, las dos personas que mande un estado competiran como un equipo.

Esto ha causado problemas en el comité de Yucatán y no saben a quienes elegir para dar los mejores resultados posibles. Para su buena suerte los entrenadores han podido calificar a cada alumno con cierta fuerza $a_i$. Sin embargo, hay un pequeño problema cada programador pertenece una fuerza **oscura** o una fuerza **brillante**. Si un programador tiene una fuerza negativa quiere decir que su fuerza en realidad es oscura y $|a_i|$ es su fuerza verdadera. La fuerza de una pareja se define como $|a_i + a_j|$. Es decir, si yo mando a alguien con fuerza $10$ y $-8$ (uno oscura y otro brillante) la fuerza de la pareja es de $|10 + (-8)| = 2$.
El comité decidió enviar a la pareja más fuerte sin importar su bando ¿Puedés determinar la fuerza resultante de dicho equipo?

# Problema

Dada la lista de la fuerza de los participantes, debes determinar cuál es la fuerza de la mejor pareja que pueden mandar

# Entrada

Un número $N$ que representa la cantidad de alumnos que tiene el estado. En la siguiente línea se te dará una lista de enteros $a_i$ que representan la fuerza de los $N$ alumnos.

# Salida

Un único entero que representa la fuerza total de la mejor pareja.

# Ejemplos

||input
5
-4 12 32 3 0
||output
44
||description
La mejor pareja es $(12, 32)$ con una fuerza de $|12 + 32| = 44$.
||input
5
4 -12 -32 -3 0
||output
44
||description
La mejor pareja es $(-12, -32)$ con una fuerza de $|-12 - 32| = 44$.
||input
3
1 1 1
||output
2
||end

# Limites

- Nota que el limite de tiempo no es normal.
- Todas las subtareas se encuentran agrupadas.

**Para un 20% de los casos**

- $2 \leq N_i \leq 100$
- $0 \leq |a_j| \leq 100$

**Para un 27% de los casos**

- $2 \leq N_i \leq 5 \times 10^4$
- $0 \leq |a_i| \leq 10^6$

**Para un 24% de los casos**

- $2 \leq N_i \leq 10^6$
- $0 \leq a_i \leq 10^6$

**Para un 29% de los casos**

- $2 \leq N_i \leq 10^6$
- $0 \leq |a_i| \leq 10^8$