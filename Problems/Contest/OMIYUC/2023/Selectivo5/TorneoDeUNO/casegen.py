import random
import numpy as np

def get_rand_wins(l, r, ask):
    if l == r: 
        return l
    mit = (l + r) // 2
    l_winner = get_rand_wins(l, mit, ask)
    r_winner = get_rand_wins(mit + 1, r, ask)
    if random.randint(0, 1) == 0:
        ask[l_winner] += 1
        return l_winner
    else:
        ask[r_winner] += 1
        return r_winner

for i in range(1, 18):
    input  = open(f"cases/{i}.in", "w")
    output = open(f"cases/{i}.out", "w")

    sz = 1 << i
    wins = np.zeros(sz, dtype=int)
    winner = get_rand_wins(0, sz - 1, wins)

    input.write(f"{i}\n")
    for ai in wins:
        input.write(f"{ai} ")
    
    output.write(f"{winner}")

    input.close()
    output.close()