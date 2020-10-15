#include "sandpiles.h"

/**
* _print_grid - Prints a grid.
* @grid: Grid to print
*/
void _print_grid(int grid[3][3])
{
int i, j;
puts("=");
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (j)
printf(" ");
printf("%d", grid[i][j]);
}
printf("\n");
}
}

/**
* sandpiles_sum -function that Sums two sandpiles
* @grid1: First sandpile.
* @grid2: Second sandpile.
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
int i, j, x;
int tmp[3][3];
for (i = 0; i < 3; i++)
for (j = 0; j < 3; j++)
grid1[i][j] += grid2[i][j];
do {
for (i = 0; i < 3; i++)
for (j = 0; j < 3; j++)
tmp[i][j] = grid1[i][j];
x = 0;
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (tmp[i][j] > 3)
{
if (!x)
_print_grid(grid1);
x = 1;
grid1[i][j] -= 4;
if (i > 0)
grid1[i - 1][j] += 1;
if (i < 2)
grid1[i + 1][j] += 1;
if (j > 0)
grid1[i][j - 1] += 1;
if (j < 2)
grid1[i][j + 1] += 1;
}
}
}
} while (x);
}
