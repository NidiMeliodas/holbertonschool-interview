#include "slide_line.h"

/**
 * merge_line - Merges an array of integers to the left or right
 * @line: Pointer to array of integers
 * @size: Number of elements in the array
 * @direction: Slide direction (SLIDE_LEFT or SLIDE_RIGHT)
 * Return: 1 if success, 0 if fail
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i;
	int temp[size]; /* No dynamic memory: use fixed-size local buffer */
	size_t idx = 0;

	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	/* Initialize temp to 0 */
	for (i = 0; i < size; i++)
		temp[i] = 0;

	if (direction == SLIDE_LEFT)
	{
		/* Step 1: Compact non-zero values to the left */
		for (i = 0; i < size; i++)
		{
			if (line[i] != 0)
				temp[idx++] = line[i];
		}

		/* Step 2: Merge adjacent equal values */
		for (i = 0; i < size - 1; i++)
		{
			if (temp[i] != 0 && temp[i] == temp[i + 1])
			{
				temp[i] *= 2;
				temp[i + 1] = 0;
			}
		}

		/* Step 3: Compact again after merge */
		idx = 0;
		for (i = 0; i < size; i++)
		{
			if (temp[i] != 0)
				line[idx++] = temp[i];
		}

		/* Fill the rest with zeros */
		while (idx < size)
			line[idx++] = 0;
	}
	else /* SLIDE_RIGHT */
	{
		/* Step 1: Compact non-zero values to the right */
		idx = size - 1;
		for (i = size; i > 0; i--)
		{
			if (line[i - 1] != 0)
				temp[idx--] = line[i - 1];
		}

		/* Step 2: Merge adjacent equal values */
		for (i = size - 1; i > 0; i--)
		{
			if (temp[i] != 0 && temp[i] == temp[i - 1])
			{
				temp[i] *= 2;
				temp[i - 1] = 0;
			}
		}

		/* Step 3: Compact again after merge */
		idx = size - 1;
		for (i = size; i > 0; i--)
		{
			if (temp[i - 1] != 0)
				line[idx--] = temp[i - 1];
		}

		/* Fill the rest with zeros */
		while ((int)idx >= 0)
			line[idx--] = 0;
	}

	return (1);
}
