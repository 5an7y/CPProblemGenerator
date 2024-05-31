import numpy as np
import random

letras = ['s', 'a', 'n', 't', 'y']
AllPermutations = []

def LlenarPermutaciones(pos, permutacion):
    if pos == 11:
        AllPermutations.append(np.copy(permutacion))
        return
    
    for i in range(5):
        permutacion[pos] = i
        LlenarPermutaciones(pos + 1, permutacion)
    
    return

LlenarPermutaciones(0, np.zeros(11, dtype=int))

random.shuffle(AllPermutations)

lista = open(f"Santysccionario.txt", "w")
for Permutacion in AllPermutations[:1000000]:
    for ai in Permutacion:
        lista.write(letras[ai])
    lista.write('\n')

lista.close()