
#define GRID_SIZE 9 //9x9
#define MIN_NUM 1
#define MAX_NUM 9
#define EMPTY 0

typedef int** grid;

grid create_grid(int[GRID_SIZE][GRID_SIZE]);
int empty_cell(int, int, grid);
int possible(int, int, int, grid);
void solve(grid);
void printg(grid);