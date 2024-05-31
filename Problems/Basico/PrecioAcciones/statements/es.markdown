# Problema

Cuentas con el historial de acciones de cierta empresa durante los siguientes $N$ días. Quieres hallar la máxima ganancia que puedes obtener con las siguientes restricciones:

- Solo puedes tener a lo más 1 acción en todo momento.
- Puedes comprar y vender acciones cuando quieras, incluso el mismo día.

# Entrada

Un entero $1 \leq N \leq 100$ indicando la cantidad de días del historial. Seguido de una línea de enteros $1 \leq a_i \leq 100$ indicando el valor de la acción de la empresa en el momento $i$.

# Salida

Un único entero representando la ganancia máxima que puedes obtener.

# Ejemplos

||input
5
3 7 9 1 5
||output
10
||description
Puedes comprar la acción en el primer día y tienes una ganancia $-3$, luego la vendes en el tercer día a $9$ y obtienes una ganancia total de $-3 + 9 = 6$. Por último, igual puedes comprar la acción nuevamente en el cuarto día y venderla en el quinto para una ganancia total de $-3 + 9 - 1 + 5 = 10$.
||input
4
1 2 3 4
||output
3
||input
6
1 5 3 1 9 12
||output
15
||end