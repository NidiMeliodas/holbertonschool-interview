# Sandpiles Sum

This project implements a simulation of sandpiles, where we compute the sum of two sandpiles and ensure that the result is stable by toppling the cells when necessary.

## Description

A sandpile is a 3x3 grid where each cell contains grains of sand. A cell is considered unstable if it has more than 3 grains of sand. If a cell is unstable, it topples, sending 1 grain of sand to each of its four adjacent cells (up, down, left, right). If a cell is on the edge of the grid, it only sends sand to the available adjacent cells.

The goal of this project is to compute the sum of two sandpiles and ensure that the resulting sandpile is stable. If the resulting sandpile is unstable, it will topple until it becomes stable. The function `sandpiles_sum` performs this operation.

## Requirements

- C programming language
- Compile the program with the following flags: `-Wall -Wextra -Werror -pedantic`

## Files

- `sandpiles.h`: Header file declaring the `sandpiles_sum` function.
- `0-sandpiles.c`: Main logic for the sandpile simulation, including the toppling and summing functions.
- `0-main.c`: Driver code for running the program (used for testing the sum of two sandpiles).

## Functionality

The `sandpiles_sum` function takes two 3x3 grids (representing two sandpiles), sums them, and topples the result until it is stable.

### Example

**Input:**

```c
int grid1[3][3] = {
    {3, 3, 3},
    {3, 3, 3},
    {3, 3, 3}
};

int grid2[3][3] = {
    {1, 3, 1},
    {3, 3, 3},
    {1, 3, 1}
};

Output

3 3 3   1 3 1
3 3 3 + 3 3 3
3 3 3   1 3 1
=
4 6 4
6 6 6
4 6 4
=
2 5 2
5 6 5
2 5 2
=
4 2 4
2 6 2
4 2 4
=
0 5 0
5 2 5
0 5 0
=
2 1 2
1 6 1
2 1 2
=
2 2 2
2 2 2
2 2 2

To compile the program, run:
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-sandpiles.c -o 0-sandpiles
Then, run the program with:
./0-sandpiles


How it Works
Sum the Grids: The sandpiles_sum function first adds the values from the two grids (grid1 and grid2).

Check Stability: After summing, the resulting grid is checked for stability. If any cell has more than 3 grains, it is unstable.

Topple the Grid: If the grid is unstable, the topple function redistributes grains from unstable cells.

Repeat Until Stable: The process repeats until the grid becomes stable, with the current state printed before each toppling.