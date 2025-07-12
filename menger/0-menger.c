#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * is_hole - Checks if a given cell should be a space
 * @row: Row index of the cell
 * @col: Column index of the cell
 *
 * Return: 1 if the cell is in a center hole, 0 otherwise
 */
int is_hole(int row, int col)
{
	while (row > 0 || col > 0)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (1);
		row /= 3;
		col /= 3;
	}
	return (0);
}

/**
 * menger - Draws a 2D Menger Sponge of a given level
 * @level: Level of the Menger Sponge to draw
 */
void menger(int level)
{
	int size, row, col;

	if (level < 0)
		return;

	size = pow(3, level);

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (is_hole(row, col))
				putchar(' ');
			else
				putchar('#');
		}
		putchar('\n');
	}
}
