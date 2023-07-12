# Historia

En los sistemas modernos requerimos procesar información en tiempo real. Por ejemplo, en sensores, tráfico de internet, transacciones, llamadas, etc. Para cada uno de estos sistemas se tienen operaciones que se van a realizar cada cierto periodo de tiempo. Por ejemplo, en un sensor de temperatura podemos tener operaciones de la forma:

- Devuélveme la mínima temperatura en la habitación cada 5 segundos.
- Devuélveme la temperatura promedio para un periodo de 10 minutos.

Para poder procesar con todas estamos operaciones hemos creado un sistema llamado Argus. Los usuarios podrán ingresar operaciones a realizar en Argus y el sistema se encargará de hacer todos los procesos necesarios. 

# Problema

Un proceso se puede identificar con dos números $Id_i$ y $Periodo_i$. Dada la lista de operaciones que tienes que hacer, tu tarea será determinar cuáles son las primeras $K$ operaciones a realizar por el sistema.

Para la pregunta $Id_i$ se va realizar esa operación por primera vez en el segundo $Periodo_i$, a partir de allí cada $Periodo_i$ segundos se llamara a la operación. En caso de que dos operaciones se realicen en el mismo segundo, deberás decir primero la de menor $Id$.

# Entrada

Se te dará un numero $N$ indicando la cantidad de operaciones que hay en el sistema. Además, se te dará un numero $K$ que indica cuantas operaciones deberás imprimir.

En las siguientes $N$ líneas se te darán dos números $Id_i$ y $Periodo_i$ que son los que identifican a cada operación.

# Salida

Deberás imprimir $K$ líneas con las próximas operaciones a realizar por el sistema.

# Ejemplos

||input
2 5
2004 200
2005 300
||output
2004
2005
2004
2004
2005
||description
Las operaciones se imprimen de acuerdo con los siguientes segundos:

- Segundo $200$: 2004
- Segundo $300$: 2005
- Segundo $400$: 2004
- Segundo $600$: 2004, 2005

||input
10 10
1 1
2 2
3 3
4 4
5 5
6 6
7 7
8 8
9 9
10 10
||output
1
1
2
1
3
1
2
4
1
5
||end

# Limites

- Todos los $Id_i$ son distintos.
- $1 \leq N \leq 10^3$.
- $1 \leq Id_i, Periodo_i \leq 10^5$.
- $1 \leq K \leq 10^4$.