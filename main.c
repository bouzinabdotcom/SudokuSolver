#include "sudoku.h"
#include <stdio.h>

int main() {

    int t[GRID_SIZE][GRID_SIZE] = {
        {5, 3, EMPTY, EMPTY, 7, EMPTY, EMPTY, EMPTY, EMPTY},
        {6, EMPTY, EMPTY, 1, 9, 5, EMPTY, EMPTY, EMPTY},
        {EMPTY, 9, 8, EMPTY, EMPTY, EMPTY, EMPTY, 6, EMPTY},
        {8, EMPTY, EMPTY, EMPTY, 6, EMPTY, EMPTY, EMPTY, 3},
        {4, EMPTY, EMPTY, 8, EMPTY, 3, EMPTY, EMPTY, 1},
        {7, EMPTY, EMPTY, EMPTY, 2, EMPTY, EMPTY, EMPTY, 6},
        {EMPTY, 6, EMPTY, EMPTY, EMPTY, EMPTY, 2, 8, EMPTY},
        {EMPTY, EMPTY, EMPTY, 4, 1, 9, EMPTY, EMPTY, 5},
        {EMPTY, EMPTY, EMPTY, EMPTY, 8, EMPTY, EMPTY, 7, 9}
    };

    grid g = create_grid(t);

    // printf("%d\n", ((grid)g)[8][4]);

    printg((grid)g);
    
    solve((grid)g);

    return 0;
}