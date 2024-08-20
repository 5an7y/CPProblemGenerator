# Problema

Deberás calcular la cantidad de días que han transcurrido desde el $día_1$ hasta el $día_2$, en el transcurso de años no bisiestos. Se darán los días en formato (*día*, *mes*). A continuación, se te deja una lista de los meses abreviados, en orden, y la cantidad de días que tiene cada uno.

- **ENE**: 31 días
- **FEB**: 28 días
- **MAR**: 31 días
- **ABR**: 30 días
- **MAY**: 31 días
- **JUN**: 30 días
- **JUL**: 31 días
- **AGO**: 31 días
- **SEP**: 30 días
- **OCT**: 31 días
- **NOV**: 30 días
- **DIC**: 31 días

# Entrada

Se darán dos líneas con el mismo formato, cada línea representa un día. Primero, se te dará un entero $d_i$ que representa el día y luego una cadena $m_i$ que es el mes en su forma abreviada.

# Salida

Deberás determinar cuántos días han transcurrido entre uno y otro.

# Ejemplos

||input
ENE 1
FEB 1
||output
31
||input
AGO 8
NOV 10
||output
94
||input
MAY 10
MAY 10
||output
0
||input
DIC 1
FEB 1
||output
62
||end

# Límites

- $m_i$ se encuentra todo en mayúsculas y será una cadena válida.
- $d_i$ se encuentra entre el rango de días del mes dado.
- Todas las subtareas se encuentran agrupadas.

**Subtarea 1 [15 puntos]**

- $m_1 = m_2$
- $d_1 \leq d_2$

**Subtarea 2 [15 puntos]**

- $m_1 = "JUL"$
- $m_2 = "AGO"$

**Subtarea 3 [20 puntos]**

- El primer día va antes que el segundo en el calendario.

**Subtarea 4 [50 puntos]**

- No hay restricciones adicionales.