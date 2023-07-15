import argparse
import os
import pathlib
import subprocess
from tqdm import tqdm

# Initialize parser
parser = argparse.ArgumentParser(description = "Program to generate the cases of a problem")
 
# Adding optional argument
parser.add_argument('path', type=pathlib.Path, help = "Directory where the problem is")
parser.add_argument('--use_solution', action='store_true', help = "Use this flag when creating your own case checker")

# Read arguments from command line
args = parser.parse_args()

path = args.path
gen_path = path/"case_generator.cpp"
exe_path = path/"case_generator.exe"
args_path = path/"cases.arg"
solution_path = path/"solution/solution.cpp"
sol_exe_path  = path/"solution/solution.exe"

# Check that files exists in the folder
if not os.path.isfile(gen_path):
    print(f"Didn't found the generator {gen_path}")
    exit()

if not os.path.isfile(args_path):
    print(f"Didn't found the cases arguments {args_path}")
    exit()

if args.use_solution:
    if not os.path.isfile(solution_path):
        print(f"Didn't found the solution {solution_path}")
        exit()
    subprocess.run(f"g++ {solution_path} -std=c++20 -o {sol_exe_path}", check=True)

# Compile the generator.cpp and parse the cases.arg
subprocess.run(f"g++ {gen_path} -I ./Libs -std=c++20 -o {exe_path}", check=True)
num_lines = sum(1 for line in open(args_path))
f = open(args_path, "r")
errors = []

# Generate cases
with tqdm(total = num_lines) as pbar:
    for case_args in f:
        case_name = case_args.split()[0]
        pbar.set_postfix(case = case_name)

        try :
            subprocess.run(f"{exe_path} {path}/cases/{case_args}", check=True)
        except subprocess.CalledProcessError as e:
            errors.append((case_name, e))
        else:
            if args.use_solution:
                input_file  = open(f"{path}/cases/{case_name}.in", 'r')
                output_file = open(f"{path}/cases/{case_name}.out", 'w')
                subprocess.run(f"{sol_exe_path}", stdin = input_file, stdout = output_file, check=True)
                input_file.close()
                output_file.close()

        pbar.update(1)

f.close()

# Show final errors
if len(errors) > 0:
    print("ERROR WHEN GENERATING SOME CASES:\n")
    print([case_name for case_name, msg in errors])
    print(f"\nError for {errors[0][0]}:\n")
    print(errors[0][1])

os.remove(exe_path)

if args.use_solution:
    os.remove(sol_exe_path)