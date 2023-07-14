import argparse
import os
import pathlib
import shutil

# Constants
template_dir = pathlib.PurePath('Examples/Template')

# Initialize parser
parser = argparse.ArgumentParser(description = "Program to create a problem using this library")
 
# Adding optional argument
parser.add_argument('path', type=pathlib.Path, help = "Directory where the problem should be wrote \"your/path/problem_name\"")
parser.add_argument('--validator', action='store_true', help = "Use this flag when creating your own case validator")

# Read arguments from command line
args = parser.parse_args()

path = args.path
p = pathlib.PurePath()

if os.path.isdir(path):
    print(f"The directory {path} already exists!")
    exit()

for x in path.parts[:-1]:
    p = p / x
    if not os.path.isdir(p):
        val = input(f"You are creating a new directory {p}, are you sure? (Y/N)")
        if val not in ["Y", "N"]:
            print("You entered an invalid option")
            exit()
        if val == "N":
            exit()
        else:
            break

shutil.copytree(template_dir, path)
if not args.validator:
    os.remove(path / 'validator.cpp')

print(f"Problem {path} created sucessfully!")