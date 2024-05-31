import random
import numpy as np

for i in range(10):
    input  = open(f"cases/{i}.in", "w")
    output = open(f"cases/{i}.out", "w")

    N = random.randint(10, 300)
    M = random.randint(10, 300)
    matrix = np.zeros((N+1, M+1), dtype=int)
    for i in range(1, N+1):
        for j in range(1, M+1):
            matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]) + random.randint(1, 1000)
    a = random.randint(1, N)
    b = random.randint(1, M)
    X = matrix[a][b]

    input.write(f'{N} {M} {X}\n')
    for i in range(1, N+1):
        for j in range(1, M+1):
            input.write(f'{matrix[i][j]} ')
        input.write('\n')
    
    input.close()
    output.close()
