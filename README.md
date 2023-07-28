# Passing Arrays - Homework #3

## Principles of Programming Languages - CU Denver - Summer 2023

#### By: Jake McKnight

A bash script has been included to run the programs using the tester file and output the results of each trial to files
called `C_Output.txt` and `PY_Output.txt`.

*Please note: the files will be over-written with new data each time the script executes.*

## How-to Run

A version of the files that ran on my Linux Ubuntu machine are included as [`C_Output_Examples.txt`](./C_Output_Example.txt) 
and [`PY_Output_Example.txt`](./PY_Output_Example.txt).

Exact run times may vary from machine to machine.

1. Clone repo into a working directory

```bash
git clone https://github.com/mcknijak/PPL-arrayPassingHW.git
```

2. Use `chmod` to allow run permissions on the `arrayPassingScript.sh` file.

```bash
chmod a+x testingScript.sh
```

3. Run the Script

```bash
./testingScript.sh
```

4. Open the newly created [`C_Output.txt`](./C_Output.txt) and [`PY_Output.txt`](./PY_Output.txt) files to view the results.


## Discussion - Python

Python is an interpreted language that is widely used for data science and I believe machine learning as well. It has a
large number of freely available modules that can be used to help speed along the development process for certain things.
It also features a large number of quality of life improvements for doing this like looping through a file or list. 
Some Python libraries are built on top of pre-compiled C code to help speed up performance since interpreted languages can be slower
in part due to their late binding times. A few of these tools and quality of life improvements were taken advantage of
for this assignment.

## Approach

To start, I went though the requirements item by item and determined the steps needed to accomplish the goal.

#### Steps 1 - 4 : Building the Reference Dictionary

To start, the .csv file containing the reference data needs to be loaded into a dictionary.
This is done by using the csv package to open the file, and then line by line it takes the first column and makes that
the key in the dictionary, and puts the second column into the value for that key. Each row therefore translates into
an entry in my dictionary.

#### Step 5 : Get the file to test

Note: to automate testing and to potentially speed up grading, instead of asking the user, the file to process is instead
passed as a argument when this program is invoked. The line to ask the user is there, but commented out.

The sys module lets me grab the filename as specified by the user. Some error checking I learned in Networking is there as well
for the arguments.

#### Steps 6 - 8 : Mapping the words of the file to the dictionary

After opening the file again, break the file down into lines, then further into words. Now, see if the word is actually
in the given dictionary. If it is, factor is value into a running counter that tracks the score for the entire file.
A few lines of output are included for debugging. I stopped outputting after the first 10 so the output wouldn't be too cluttered.

#### Step 9 : Turn the Score into a Star value

Finally, use a helper function to turn the file's score into a Star value 1-5 and output the resulting numbers.

### Particular Details

Since Python is often used in data analysis and machine learning and we are analyzing sets of data, it seemed a logical choice
for this assignment. Indeed, the ease of opening files and looping through their contents was appreciated as was the ease 
of populating a dictionary of indeterminate size. No major complaints as Python is weel-equipped for tasks in this arena.

## Discussion - C

### Abstract 

C is a general purpose, procedural language that is extremely powerful and influential in the world of computing. It is
compiled and while it does have support for simple structures, it does not support object-oriented programming. It also
does not come with support for a dictionary/hash map data structure, which is the first data structure that came to mind
for this problem. 

## Approach

To start, I went though the requirements item by item and determined the steps needed to accomplish the goal.

#### Steps 1 - 4 : Building the Reference Dictionary

To start, the .csv file containing the reference data needs to be loaded into a dictionary.
Since C doesn't have as many since packages as Python, a lot of this needed to be done manually with a few tricks.
Key/Value pairs were stored as a structure and then all of them were stored in a giant list. I manually looked at how big the .csv file was and 
used that to set how big of an array i needed to store all of these Key/Value pair structs. Since I used heap memory allocation in 
Network Programming, I tried to use the stack this time to store my massive dictionary-esque array. One notable change is that since this
is an array, looking up specific Pairs takes much longer - O(n) vs O(1).

#### Step 5 : Get the file to test

Note: to automate testing and to potentially speed up grading, instead of asking the user, the file to process is instead
passed as a argument when this program is invoked. The line to ask the user is there, but commented out.

C will grab the first argument passed when the executable is invoked and use that as the review file. the .csv file is hard-coded in since it doesn't change.

#### Steps 6 - 8 : Mapping the words of the file to the dictionary

After opening the file again, break the file down into lines, then further into words. Now, see if the word is actually
in the given dictionary. If it is, factor is value into a running counter that tracks the score for the entire file.
A few lines of output are included for debugging. I stopped outputting after the first 10 so the output wouldn't be too cluttered.

This had to be done much more carefully in C since special attention has to be paid to the typing, the pointers, and the size of the data being accessed.

#### Step 9 : Turn the Score into a Star value

Finally, use a helper function to turn the file's score into a Star value 1-5 and output the resulting numbers.


### Particular Details

The main difference I felt is that Python has tools that handles thing like typing and memory allocation for the programmer. In C,
the programmer has to be aware of everything that is required to get a task done and ensure that buffers are being correctly reset and that no
issues with memory allocation appear. I see value in both depending on the task. It is definitely nice to have some of the leg work handled for you,
but I for sure see the value - especially for tracking down unexpected behaviors and debugging - in being in complete control of everything that is happening in the program. You get this control in C but have some of it abstracted away in Python.