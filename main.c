#include "sudoku.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


grid filetogrid(char* filename, int t[GRID_SIZE][GRID_SIZE]) {
    FILE *f = fopen(filename, "r");

    if(f == NULL)
   {
      printf("File Error! %s isn't valid\n", filename);   
      exit(1);             
   }

    
    char tmp;

    int j;
    for(int i=0; i<GRID_SIZE; i++)
        for(j=0; j<GRID_SIZE; j++){
            
            fscanf(f, "%c", &tmp);
            if(feof(f)) break;
            if(tmp != '\n'){
                t[i][j] = tmp-48;

            }
            else j--;
        }

    if(j!=GRID_SIZE) {
        printf("%s has an invalid format\n", filename);
        exit(EXIT_FAILURE);
    }

    fclose(f); 
    return create_grid(t);
}

int main(int argc, char* argv[]) {

    int t[GRID_SIZE][GRID_SIZE];
    switch(argc) {
        case 2: 
                if (strcmp(argv[1], "-h")==0 ||strcmp(argv[1], "--Help")==0) 
                    puts("sudoku-solver [-a|--All] filename");
                
                else solve(filetogrid(argv[1], t));
                break;
        case 3: if(strcmp(argv[1], "-a")==0 ||strcmp(argv[1], "--All")==0) 
                    solveAll(filetogrid(argv[2], t));
                else{
                    puts("sudoku-solver: I'm sorry this option isn't supported.");
                    exit(EXIT_FAILURE);
                }
                break;
        case 1: puts("sudoku-solver: I need at least one argument.");
                puts("for help: sudoku-solver -h ");
                exit(EXIT_FAILURE);
        default: puts("sudoku-solver: too many arguments");
                 puts("for help: sudoku-solver -h ");
                 exit(EXIT_FAILURE);
    }
    

    return 0;
}