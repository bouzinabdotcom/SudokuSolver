#include "sudoku.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>



grid create_grid(int t[GRID_SIZE][GRID_SIZE]){
    grid g = (grid)malloc(GRID_SIZE * sizeof(int*));
    for(int i=0; i<GRID_SIZE; i++){
        *(g+i) = *(t+i);

    }


    return g;
}

int empty_cell(int i, int j, grid g){
    return g[j][i] == EMPTY;
}

int possible(int x, int y, int n, grid g) {
    assert(x<GRID_SIZE && y<GRID_SIZE);
    
    //check line
    for(int i = 0; i<GRID_SIZE; i++){
        if(g[x][i] == n)
            return 0;
    }

    //check column
    for(int j = 0; j<GRID_SIZE; j++){
        if(g[j][y] == n)
            return 0;
    }

    //check 3x3 square
    for(int j=(x/3)*3; j<(x/3)*3+3; j++ )
        for(int i=(y/3)*3; i<(y/3)*3+3; i++)
            if(g[j][i] == n)
                return 0;

    return 1;
}



void solve(grid g) {
    for(int j = 0; j<GRID_SIZE; j++){
        for(int i = 0; i<GRID_SIZE; i++){
            if(empty_cell(i, j, g)){
                for(int n=MIN_NUM; n<=MAX_NUM; n++){
                    if(possible(j, i, n, g)){
                        g[j][i] = n;
                        solve(g);
                        g[j][i]=EMPTY;
                        
                    }
                    
                }
                return;
                
            }
        }
    } 
    printg(g);
    exit(EXIT_SUCCESS);
}
void solveAll(grid g) {
    for(int j = 0; j<GRID_SIZE; j++){
        for(int i = 0; i<GRID_SIZE; i++){
            if(empty_cell(i, j, g)){
                for(int n=MIN_NUM; n<=MAX_NUM; n++){
                    if(possible(j, i, n, g)){
                        g[j][i] = n;
                        solveAll(g);
                        g[j][i]=EMPTY;
                        
                    }
                    
                }
                return;
                
            }
        }
    } 
    printg(g);
}

void printg(grid g) {
    int i, j;
    printf(" _ _ _  _ _ _  _ _ _  \n");
    for(j = 0; j<GRID_SIZE; j++){
        printf("|");
        for(i = 0; i<GRID_SIZE; i++){

            if(!empty_cell(i, j, g)) printf("%d ", g[j][i]);            
            else printf("# ");

            if((i+1)%3 == 0 && i+1!=GRID_SIZE) printf("|");
        }
        printf("|\n");
        if((j+1)%3 == 0 && j+1!=GRID_SIZE) printf(" _ _ _  _ _ _  _ _ _  \n");
    }
    printf(" _ _ _  _ _ _  _ _ _  \n");
}