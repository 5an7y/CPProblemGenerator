import argparse
import os
import pathlib
import subprocess
import time
import shutil

def solution_ok(c_path, case_name):
    case_out_path = f"{c_path}/{case_name}.out" 
    user_sol_path = f"{c_path}/{case_name}_sol.out"
    
    if validator:
        case_in_path = f"{c_path}/{case_name}.in"

        shutil.copyfile(case_in_path,  f"data.in")
        shutil.copyfile(case_out_path, f"data.out")
        f = open(user_sol_path, "r")
        f_out = open(f"{path}/rank.txt", "w")

        subprocess.run(f"{validator_exe}", stdin = f, stdout = f_out, timeout=20000, check=True)
        f.close()
        f_out.close()
        with open(f"{path}/rank.txt") as f:
            ranked = [float(x) for x in next(f).split()][0] # read first line
            return ranked
    else:
        except_output = []
        solution_output = []

        f = open(case_out_path, "r")
        for x in f:
            output = x.split()
            if len(output) > 0:
                except_output += output
        f.close()

        f = open(user_sol_path, "r")
        for x in f:
            output = x.split()
            if len(output) > 0:
                solution_output += output
        f.close()

        return except_output == solution_output

def run_case(case, exe_p, is_group = False):
    if is_group:
        tab = "\t\t"
    else:
        tab = "\t"
    print(f"{tab}{case}: Running...", end='\r')
    veredict = ""
    case_score = 0.0
    case_total = cases_weights[case]
            
    start = time.time()
    input_file = open(f"{cases_path/case}.in", 'r')
    output_file = open(f"{cases_path/case}_sol.out", 'w')
    
    try:
        subprocess.run(f"{exe_p}", stdin = input_file, stdout = output_file, timeout=time_limit, check=True)
    except subprocess.TimeoutExpired:  
        print(f"{tab}{FAIL_COLOR}{case}: {CROSS} [TLE, scr = 0/{case_total:.2f}] {END_COLOR}")
        veredict = "TLE"
    except subprocess.CalledProcessError:
        print(f"{tab}{FAIL_COLOR}{case}: {CROSS} [RTE, scr = 0/{case_total:.2f}] {END_COLOR}")
        veredict = "RTE"
    else:
        end = time.time()
        elapsed_time = (int) ((end - start) * 1000)
        ranking = (float) (solution_ok(cases_path, case))
        if ranking == 1.0:
            veredict   = "AC"
            case_score = case_total
            print(f"{tab}{OK_COLOR}{case}: {CHECK} [AC, ms = {elapsed_time}, scr = {case_score:.2f}]{END_COLOR}")
        elif ranking > 0:
            veredict   = "PA"
            case_score = ranking * case_total
            print(f"{tab}{WARNING}{case}: {CROSS} [PA, ms = {elapsed_time}, scr = {case_score:.2f}/{case_total:.2f}]{END_COLOR}")
        else:
            print(f"{tab}{FAIL_COLOR}{case}: {CROSS} [WA, ms = {elapsed_time}, scr = 0/{case_total:.2f}]{END_COLOR}")
            veredict = "WA"

    input_file.close()
    output_file.close()
    os.remove(f"{cases_path}/{case}_sol.out")
    return (veredict, case_score)

def test_solution(solution, groups):
    print(f"Testing {solution}:")

    sol_p = solutions_path / solution
    exe_p = solutions_path / (solution[:-4] + ".exe")
    try:
        subprocess.run(f"g++ {sol_p} -std=c++20 -o {exe_p}", check=True)
    except :
        print(f"\t{FAIL_COLOR}COMPILATION ERROR{END_COLOR}")
        return 0

    mapeo = {
        "AC"  : 0,
        "PA"  : 0,
        "TLE" : 0,
        "RTE" : 0,
        "WA"  : 0
    }
    score = 0.0

    for group_name, group in groups.items():
        group_score = 0.0
        has_group_points = True
        is_group = len(group) > 1
        total_case_score = 0
        for case in group:
            veredict, case_score = run_case(case, exe_p, is_group)
            group_score += case_score
            total_case_score += cases_weights[case]
            mapeo[veredict] += 1
            if is_group and veredict != "AC":
                has_group_points = False     
        
        if has_group_points:
            score += group_score
        
        if is_group:
            if has_group_points:
                print(f"\t{OK_COLOR}{group_name}: {CHECK} [AC, score = {group_score:.2f}]{END_COLOR}")
            else:
                print(f"\t{FAIL_COLOR}{group_name}: {CROSS} [WA, score = 0/{total_case_score:.2f}]{END_COLOR}")

    os.remove(exe_p)
    score = (score / total_weight) * 100

    print(f"AC = {mapeo['AC']}, WA = {mapeo['WA']}, PA = {mapeo['PA']}, TLE = {mapeo['TLE']}, RTE = {mapeo['RTE']}, Score = {score:.2f}%")
    print("--------------------------------------------------------------------------------------")
    return score

# Initialize parser
parser = argparse.ArgumentParser(description = "Program to generate the cases of a problem")

# Adding arguments
parser.add_argument('path', type=pathlib.Path, help = "Directory where the problem is")
parser.add_argument('--time_limit', type=int, default=5000, help = "Time Limit in ms")
parser.add_argument('--solutions', type=str, nargs='*', default=[], help = "List of solutions to be test it (if none, all will be tested)")
parser.add_argument('--cases', type=str, nargs='*', default=[], help = "List of cases to be tested (if none, all will be tested)")
parser.add_argument('--validator', action='store_true', help = "Use this flag when using your own validator")

# Read arguments from command line
args = parser.parse_args()

path = args.path
solutions_path = path/"solution"
cases_path = path/"cases"
time_limit = args.time_limit / 1000
solutions = args.solutions
tested_cases = args.cases
validator = args.validator
validator_path = path/"validator.cpp"
validator_exe = path/"validator.exe"

# Constants
FAIL_COLOR = '\033[91m'
OK_COLOR   = '\033[92m'
END_COLOR  = '\033[0m'
CHECK      = '\u2713'
CROSS      = '\u2717'
WARNING    = '\033[93m'

# Check if all cases have an in and out file
cases = [os.path.splitext(case)[0] for case in os.listdir(cases_path)]
all_cases = list(dict.fromkeys(cases))
if len(tested_cases) > 0:
    cases = tested_cases

cases = list(dict.fromkeys(cases))
cases_weights = dict()
for case in cases:
    if not os.path.isfile(cases_path / (case + ".in")):
        print(f"Missing case {case}.in")
        exit()
    if not os.path.isfile(cases_path / (case + ".out")):
        print(f"Missing case {case}.out")
        exit()
    cases_weights[case] = 1

if validator:
    if not os.path.isfile(validator_path):
        print(f"Missing validator.cpp")
        exit()
    subprocess.run(f"g++ {validator_path} -std=c++20 -o {validator_exe}", check=True)

testplan_detected = False
testplan_path = path/"testplan"
total_weight = len(cases)

if os.path.isfile(testplan_path) :
    print("Testplan detected. Checking testplan...")
    testplan_detected = True
    f = open(testplan_path, "r")
    total_weight = 0
    for case_testplan in f:
        case_name   = case_testplan.split()[0]
        case_weight = (int)(case_testplan.split()[1])
        if case_name not in all_cases:
            print(f"Case {case_name} in testplan but no in cases")
            f.close()
            exit()
        cases_weights[case_name] = case_weight
        total_weight += case_weight
    f.close()
    if total_weight == 0:
        print(f"Error: Total weight in testplan is 0.")
        exit()
    print("Testplan ok.")

# Extract groups cases
groups = dict()
for case in cases:
    case_group = case.split(".")[0]
    if case_group in groups:
        groups[case_group].append(case)
    else:
        groups[case_group] = [case]

# Run the solutions against each case
print()
sol_map = {}
for solution in os.listdir(solutions_path):
    if not solution.endswith('.cpp'):
        continue
    if len(solutions) > 0 and solution not in solutions:
        continue

    score = test_solution(solution, groups)
    sol_map[solution] = f"{score:.2f}"

print("Resumen:")
for key, value in sol_map.items():
    print(f"\t{key} = {value}%")

if validator:
    os.remove(validator_exe)
    os.remove('data.in')
    os.remove('data.out')
    os.remove(path / 'rank.txt')