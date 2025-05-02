#include <stdio.h>

#define SIZE 3

/**
 * print_grid - Print a 3x3 grid
 * @grid: The grid to print
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - Check if the grid is stable
 * @grid: The grid to check
 *
 * Return: 1 if stable, 0 otherwise
 */
static int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * topple - Topples the unstable sandpile
 * @grid: The main grid to be modified
 */
static void topple(int grid[3][3])
{
	int i, j;
	int tmp[3][3] = {{0}};

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (grid[i][j] > 3)
			{
				tmp[i][j] -= 4;
				if (i > 0)
					tmp[i - 1][j]++;
				if (i < SIZE - 1)
					tmp[i + 1][j]++;
				if (j > 0)
					tmp[i][j - 1]++;
				if (j < SIZE - 1)
					tmp[i][j + 1]++;
			}
		}
	}

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			grid[i][j] += tmp[i][j];
		}
	}
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: The first grid (result stored here)
 * @grid2: The second grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	// Sum the two grids
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	// Topple until stable
	while (!is_stable(grid1))
	{
		print_grid(grid1);
		topple(grid1);
	}
}
