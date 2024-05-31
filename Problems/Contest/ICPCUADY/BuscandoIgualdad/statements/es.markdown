# Problema

El plan de Santy no le funciono del todo ya que algunos alumnos se molestaron al quitarles dinero. Para arreglarlo, ha decidido aumentar todos con la finalidad de conseguir la justicia económica (que todos reciban lo mismo). Sin embargo, Santy no es tonto; él quiere lograr esto con la **mínima** cantidad de dinero posible.

Se te darán los montos de los apoyos actuales y deberás determinar la cantidad mínima de dinero que debes gastar para hacerlos todos iguales. Únicamente puedes dar dinero; quitarle dinero a los alumnos los pondría de mal humor.

# Entrada

Se te dará un entero $1 \leq N \leq 1000$ que indica la cantidad de alumnos que actualmente reciben un apoyo económico. Luego, se te darán los enteros $1 \leq a_i \leq 1000$ que indican los montos que reciben actualmente.

# Salida

Deberás imprimir la cantidad mínima de dinero que se debe dar para hacer todos los montos iguales.

# Ejemplos

||input
5
3 4 3 4 4
||output
2
||description
Si a los dos que reciben 3, les damos uno y uno, entonces ya todos recibirían un monto de 4 y habría una justicia económica.
||input
10
1 2 3 4 5 6 7 8 9
||output
36
||input
1
10
||output
0
||input
2
5 5
||output
0
||end