import argparse
import os
import pathlib
import subprocess
import time

def solution_ok(c_path, case_name):
    except_output = []
    solution_output = []

    f = open(f"{c_path}/{case_name}.out", "r")
    for x in f:
        output = x.split()
        if len(output) > 0:
            except_output += output
    f.close()

    f = open(f"{c_path}/{case_name}_sol.out", "r")
    for x in f:
        output = x.split()
        if len(output) > 0:
            solution_output += output
    f.close()

    return except_output == solution_output

# Initialize parser
parser = argparse.ArgumentParser(description = "Program to generate the cases of a problem")

# Adding arguments
parser.add_argument('path', type=pathlib.Path, help = "Directory where the problem is")
parser.add_argument('--time_limit', type=int, default=1000, help = "Time Limit in ms")

# Read arguments from command line
args = parser.parse_args()

path = args.path
solutions_path = path/"solution"
cases_path = path/"cases"
time_limit = args.time_limit / 1000

FAIL_COLOR = '\033[91m'
OK_COLOR   = '\033[92m'
END_COLOR  = '\033[0m'
CHECK      = '\u2713'
CROSS      = '\u2717'

cases = [os.path.splitext(case)[0] for case in os.listdir(cases_path)]
cases = list(dict.fromkeys(cases))

for case in cases:
    if not os.path.isfile(cases_path / (case + ".in")):
        print(f"Missing case {case}.in")
        exit()

    if not os.path.isfile(cases_path / (case + ".out")):
        print(f"Missing case {case}.out")
        exit()

total_cases = len(cases)

print()

sol_map = {}
for solution in os.listdir(solutions_path):
    if not solution.endswith('.cpp'):
        continue

    print(f"Testing {solution}:")

    sol_p = solutions_path / solution
    exe_p = solutions_path / (solution[:-4] + ".exe")
    
    try:
        subprocess.run(f"g++ {sol_p} -std=c++20 -o {exe_p}", check=True)
    except :
        print(f"\t{FAIL_COLOR}COMPILATION ERROR{END_COLOR}")

    mapeo = {
        "AC"  : 0,
        "TLE" : 0,
        "RTE" : 0,
        "WA"  : 0
    }
    for case in cases:
        print(f"\t{case}: Running...", end='\r')

        start = time.time()
        input_file = open(f"{cases_path/case}.in", 'r')
        output_file = open(f"{cases_path/case}_sol.out", 'w')
        
        try:
            subprocess.run(f"{exe_p}", stdin = input_file, stdout = output_file, timeout=time_limit, check=True)
        except subprocess.TimeoutExpired:  
            print(f"\t{FAIL_COLOR}{case}: {CROSS} [TLE] {END_COLOR}")
            mapeo["TLE"] += 1
        except subprocess.CalledProcessError:
            print(f"\t{FAIL_COLOR}{case}: {CROSS} [RTE] {END_COLOR}")
            mapeo["RTE"] += 1
        else:
            end = time.time()
            elapsed_time = (int) ((end - start) * 1000)
            if solution_ok(cases_path, case):
                print(f"\t{OK_COLOR}{case}: {CHECK} [AC, ms = {elapsed_time}]{END_COLOR}")
                mapeo["AC"] += 1
            else:
                print(f"\t{FAIL_COLOR}{case}: {CROSS} [WA, ms = {elapsed_time}]{END_COLOR}")
                mapeo["WA"] += 1

        input_file.close()
        output_file.close()
        os.remove(f"{cases_path}/{case}_sol.out")

    os.remove(exe_p)
    score = (mapeo["AC"] / total_cases) * 100
    print(f"AC = {mapeo['AC']}, WA = {mapeo['WA']}, TLE = {mapeo['TLE']}, RTE = {mapeo['RTE']}, Score = {score:.2f}%")
    print("--------------------------------------------------------------------------------------")
    sol_map[solution] = f"{score:.2f}"

print("Resumen:")
for key, value in sol_map.items():
    print(f"\t{key} = {value}%")