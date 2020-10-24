all: main.o sudoku.o
	  gcc main.o sudoku.o -o sudoku-solver

sudoku.o: sudoku.c
		  gcc -c sudoku.c

main.o: main.c
		gcc -c main.c


clean: 
	rm -rf *.o