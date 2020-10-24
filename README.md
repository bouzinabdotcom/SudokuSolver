# SUDOKU Solver

A basic 9x9 sudoku solver cli tool written in C.


# Compile

Clone project:

    $ git clone https://github.com/bouzinabdotcom/SudokuSolver

Go to directory:

    $ cd SudokuSolver
Make:

    $ make


## Sudoku Solver File Format

To use this tool you will need a text file with the sudoku puzzle you wish to solve.
An example of that file is provided (example.sdks). The ".sdks" extension is optional.
The text file should have the following format: Put each line of the sudoku grid on a seperate line.

**Example:** 

![enter image description here](https://upload.wikimedia.org/wikipedia/commons/e/e0/Sudoku_Puzzle_by_L2G-20050714_standardized_layout.svg)

**.sdks format:** 
 
530070000  
600195000  
098000060  
800060003  
400803001  
700020006  
060000280  
000419005  
000080079  

## How to use

To get 1 solution for the puzzle: 

    $ ./sudoku-solver example.sdks

To get all possible solutions :

    $ ./sudoku-solver -a example.sdks
Or

    $ ./sudoku-solver -All example.sdks

## Wanna have some fun ?

Make a sdks file with an empty grid (everything is 0). 
Then look for all the solutions and put them in a file.

    $ ./sudoku-solver -All all.sdks > sudoku-universe.txt

Sudoku has 6, 670, 903, 752, 021, 072, 936, 960 solutions. Once the execution stops (it's gonna take a lot of time) you'll have all of them in a (huge) text file.

Have fun!
