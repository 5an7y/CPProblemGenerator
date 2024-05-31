# Descripción

_"¡Estamos hartos de estos locos juegos de mesa!"_ exclamaron los olímpicos. Por esta razón, Sebastián les ha presentado un juego NO DE MESA, pero bastante sencillo: un crucigrama. Para aquellos que no lo sepan, un crucigrama es un juego en el que se llenan palabras usando pistas proporcionadas.

![](Crucigrama.png)

En un crucigrama típico, se proporcionan pistas para todas las palabras, y con esas pistas se puede deducir la respuesta para cada una. En ocasiones, algunas palabras se vuelven muy complicadas y es más conveniente resolver primero otras pistas para obtener letras que ayuden con la palabra complicada. Sin embargo, el crucigrama de Sebastián es un tanto peculiar.

- El primer punto a destacar es que utiliza el [Santyccionario](https://drive.google.com/file/d/1yHLwjG06VSBU4_GNdTa59YLvEcJGwLsG/view?usp=sharing), un diccionario de palabras compuestas únicamente por las letras [`s`, `a`, `n`, `t`, `y`], y todas las palabras tienen exactamente 11 caracteres.
- Todas las palabras, **EXCEPTO UNA**, tienen una pista asociada.
- El objetivo de este crucigrama no es completarlo en su totalidad. Tu tarea será determinar cuántas palabras son válidas para rellenar la palabra faltante.

# Problema

Estás en un punto del juego donde has completado todas las palabras excepto la última. Tu tarea será determinar cuántas de las palabras en el Santyccionario son válidas para completar la palabra faltante.

# Entrada

Se te proporcionará en un archivo de texto la sección relevante del crucigrama. Consiste en 11 líneas de texto, donde algunas líneas contienen una palabra y otras solo contienen una "X". Tu tarea es encontrar cuántas palabras pueden encajar en la línea vertical marcada por las "X". Se asegura que si la línea $i$ contiene una palabra, entonces la línea $i + 1$ contiene una "X". Ver el ejemplo.

{{output-only:download}}

# Salida

Debes enviar un archivo `zip` con las respuestas correspondientes. Si un archivo se llama `1.in`, tu `zip` deberá contener un `1.out` con la cantidad de palabras que pueden encajar en ese caso.

# Ejemplo

Para los siguientes ejemplos no usaremos el diccionario real del archivo. Solo es para ilustrar cómo se ven los archivos.

||input
nnsty
  X
 tnsys
  X
  X
||output
3
||description
Si nuestro diccionario SOLO tuviera las palabras {`santy`, `santt`, `aanty`, `snnty`, `tnnys`, `nnsty`}, entonces las únicas palabras que serían válidas para la vertical faltante son {`santy`, `santt`, `snnty`}.
||end

# Límites

- Todas las palabras tienen 11 caracteres.
- Todos los casos constan exactamente de 11 líneas.
- Todas las palabras están compuestas únicamente por las letras mencionadas anteriormente.
- Los casos pueden contener espacios al inicio de las palabras.