import random
import re

letras = ['s', 'a', 'n', 't', 'y']

f = open("Santysccionario.txt", "r")
wordDic = []
for x in f:
  wordDic.append(x)
f.close()

def count_matching_strings(regex, string_list):
    pattern = re.compile(regex)
    matching_count = 0
    
    for string in string_list:
        if pattern.match(string):
            matching_count += 1
    
    return matching_count

def generateRegex():
    word = ""
    wildcards = 0
    for _ in range(11):
        if (len(word) == 0 or word[-1] == "w") and random.random() < 0.5:
            word += random.choice(letras)
        else :
            word += '\w'
            wildcards += 1
    return word, wildcards

def get_regex_match(regex, string_list):
    pattern = re.compile(regex)
    
    for string in string_list:
        if pattern.match(string):
            return string
    

respuestas = []

for i in range(10):
    regexCounts = 0
    allCount = 0

    while regexCounts <= 2 or regexCounts >= allCount - 3 :
        myRegex, allCount = generateRegex()
        allCount = 5 ** allCount
        regexCounts = count_matching_strings(myRegex, wordDic)
    
    output = open(f"cases/{i}.out", "w")
    output.write(str(regexCounts))
    output.close()

    aux = []
    left_shift = 0
    for ai in myRegex:
        if ai in letras:
            aux.append(get_regex_match(f"\w+{ai}\w+", wordDic))
            left_shift = max(left_shift, aux[-1].index(ai))

    input = open(f"cases/{i}.in", "w")
    ite = 0

    for ai in myRegex:
        if ai in letras:
            this_shift = aux[ite].index(ai)
            input.write(" " * (left_shift - this_shift))
            input.write(aux[ite])
            ite += 1
        elif ai == 'w':
            input.write(" " * left_shift)
            input.write("X")
            input.write("\n")
    input.close()