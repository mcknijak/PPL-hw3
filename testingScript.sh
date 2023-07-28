#!/bin/bash

make

printf "%s\n\n" "------------------------------------------Running test w/ 'review.txt'-------------------------------------------" > C_Output.txt

./socialScores_C review.txt >> C_Output.txt

printf "%s\n\n" "------------------------------------------Running test w/ 'good.txt'-------------------------------------------" >> C_Output.txt

./socialScores_C good.txt >> C_Output.txt

printf "%s\n\n" "------------------------------------------Running test w/ 'bad.txt'-------------------------------------------" >> C_Output.txt

./socialScores_C bad.txt >> C_Output.txt

make clean

printf "%s\n\n" "------------------------------------------Running test w/ 'review.txt'-------------------------------------------" > PY_Output.txt

python3 socialScores_PY.py review.txt >> PY_Output.txt

printf "%s\n\n" "------------------------------------------Running test w/ 'good.txt'-------------------------------------------" >> PY_Output.txt

python3 socialScores_PY.py good.txt >> PY_Output.txt

printf "%s\n\n" "------------------------------------------Running test w/ 'bad.txt'-------------------------------------------" >> PY_Output.txt

python3 socialScores_PY.py bad.txt >> PY_Output.txt

printf "\nAll test successfully run, please view the '*_Output.txt' files for results.\n"