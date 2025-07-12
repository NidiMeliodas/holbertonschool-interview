#!/usr/bin/python3
import sys

def is_safe(queen, queens):
    for r, c in enumerate(queens):
        if c == queen or abs(c - queen) == len(queens) - r:
            return False
    return True

def solve_nqueens(n, row=0, queens=[], solutions=[]):
    if row == n:
        solutions.append([[i, col] for i, col in enumerate(queens)])
        return

    for col in range(n):
        if is_safe(col, queens):
            solve_nqueens(n, row + 1, queens + [col], solutions)

def main():
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = []
    solve_nqueens(n, solutions=solutions)
    for sol in solutions:
        print(sol)

if __name__ == "__main__":
    main()
