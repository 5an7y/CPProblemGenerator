# Historia

Todos conocen al gran pintor e inventor Leonardo Da Caprio, lo que muchos no saben es que este artista contaba con un hermano llamado Leonardo Da Vinci. Lamentablemente este último siempre tenía que vivir en la sombra de su hermano, por más bueno que era pintando su hermano era el mejor. Lamentablemente un día Da Caprio fallece, al fallecer sus obras empiezan a tomar aún más valor. Mas aun, esas obras que tenía sin publicar en su estudio adquieren precios extraordinarios. Al ver este suceso, su hermano empieza a crear obrar que parezcan que fueron de su hermano.

A Da Caprio se le conocía por sus obras majestuosas en una dimensión. Si el recuadro donde pintaba tenía $N$ espacios, el usaba a lo más $N$ colores numerados del $1$ al $N$. El recuadro inicialmente está en blanco (con el color $0$). Además, su forma de pintar era hacer los siguientes pasos:

- Elige un color de los que tiene.
- Para ese color elige un rango $[a, b]$ ($1 \leq a \leq b \leq N$).
- Pinta todos los espacios entre $[a, b]$ del color correspondiente.
- Desecha el color usado y ya no lo puede volver a usar.
- Espera a que se seque la pintura y vuelve a pintar.

Los colores que usaba son mágicos y cada que pintaba un espacio de un color, se quedaba con ese color sin importar lo que había antes. Sin embargo, su hermano al momento de copiarlo fue un poco más inteligente con el tiempo y usaba los siguientes pasos:

- Elige una cantidad de colores de los que tiene $c_1, ..., c_k$.
- Para cada color elije un intervalo de tal forma que ninguno intervalo se interseque $[a_1, b_1], [a_2, b_2], ..., [a_k, b_k]$ ($1 \leq a_1 \leq b_1 < a_2 \leq b_2 < ... < a_k \leq b_k \leq N$).
- Cada intervalo lo pinta de su color correspondiente.
- Desecha los colores usados y no los puede volver a usar.
- Espera a que se seque la pintura y vuelve a pintar.

Tú sabes esta historia, entonces al momento de ver una pintura primero te preguntas si pudo haber sido creada por Da Caprio y si es así, especulas que pudo haber sido una copia de su hermano y te preguntas ¿Cuantas pasadas (pasos) tuvo que hacer su hermano mínimo para hacer esta pintura? Tu tarea será responder esta pregunta

# Problema

Se te dará un arreglo de tamaño $N$ con elementos $a_i$ representando una pintura, cada elemento representa el color en dicha posición. Deberás imprimir $-1$ si la pintura no pudo haber sido creada por Da Caprio o en caso de que si, calcula la cantidad mínima de pasos que su hermano tuvo que hacer si fue el que pintó dicha obra.

# Entrada

Se te dará un numero $N$ indicando el tamaño del recuadro. En la siguiente línea $N$ números $a_i$ indicando el color del recuadro en la posición $i$. ($0$ indica un espacio en blanco)

# Salida

$-1$ en caso de que la obra no pudo ser pintaba por Da Caprio. De caso contrario, la cantidad mínima de pasos que tuvo que hacer su hermano si fuera el quien pinto la obra.

# Ejemplos

||input
7
0 1 4 5 1 3 3
||output
2
||description
El intervalo del $1$ tuvo que haber sido pintando antes que el del $4$ y $5$. Por lo tanto, al menos se necesitan dos rondas.
||input
6
5 3 6 1 3 5
||output
3
||end

# Limites

- $1 \leq N \leq 10^6$.

**Para un 40% de los casos**

- $1 \leq N \leq 10^4$