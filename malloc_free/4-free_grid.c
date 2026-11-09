#include "main.h"

/**
 * free_grid - frees a 2 dimensional grid
 * @grid: the grid to free
 * @height: height of the grid
 *
 * Return: void
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL)
		return;

	for (i = 0; i < height; i++)
		free(grid[i]);

	free(grid);
}
