---
title: "Solución FindShip"
author: José Santiago Vales Mena
date: Agosto 14, 2023
geometry: "left=3cm,right=3cm,top=2cm,bottom=2cm"
output: pdf_document
header-includes:
    - \usepackage{setspace}
    - \onehalfspacing
---


# Solución

La parte clave del problema era notar que para los 100 puntos nos daban un máximo de preguntas proporcional a la cantidad de filas y columnas de la matriz. Esto nos indica que en cada pregunta que hagamos debemos descartar ya sea una fila o una columna de la misma.

Notemos que al hacer una pregunta tenemos tres posibles resultados: el elemento es mayor que el que buscamos, el elemento es menor que el que buscamos y el elemento es el que buscamos. Si tenemos el tercer caso, hemos terminado. Entonces, debemos hallar una pregunta que, ya sea en el primer o el segundo caso, nos permita descartar una fila o columna entera. Esto lo podemos lograr **preguntando por la esquina superior derecha o la esquina inferior izquierda**. Si preguntamos por la esquina superior derecha, tenemos los siguientes casos:

- **El elemento es mayor que el que buscamos**: En este caso, podemos descartar **toda la columna**. Al ser el primer elemento de la columna, todos los demás resultan ser mayores y, por tanto, ninguno de ellos será la respuesta.
- **El elemento es menor que el que buscamos**: En este caso, podemos descartar **toda la fila**. Al ser el último elemento de la fila, todos los demás resultan ser menores y, por tanto, ninguno de ellos será la respuesta.

Entonces, podemos ir descartando filas y columnas en cada pregunta hasta llegar a la respuesta esperada.


```cpp
#include "FindShip.h"

// Main
//	int Conocer(int x, int y)

void Encontrar(int N, int M, int X) {
    int verticalInferior = 0,
        verticalSuperior = N - 1,
        horizontalInferior = 0,
        horizontalSuperior = M - 1;

    while (verticalInferior < verticalSuperior && horizontalInferior < horizontalSuperior) {
        int A = Conocer(verticalInferior, horizontalSuperior);
        if (A == X) return;
        if (A < X) verticalInferior++;
        if (A > X) horizontalSuperior--;
    }
    return;
}
```