# Minimum Operations

This project implements an algorithm to determine the **minimum number of operations** required to produce exactly `n` copies of the character `H` in a text file using only two operations: **Copy All** and **Paste**.

---

## Requirements

### General

- Allowed editors: `vi`, `vim`, `emacs`
- OS: Ubuntu 14.04 LTS
- Interpreter: `python3` (version 3.4.3)
- All files must:
  - End with a new line
  - Start with this exact line: `#!/usr/bin/python3`
  - Be executable
  - Be documented
  - Follow **PEP 8** style guide (version 1.7.x)
- A `README.md` file at the root of the project folder is mandatory

---

## Task

### 0. Minimum Operations

**Mandatory**

In a text file, there is a single character `H`.  
Your text editor can only perform two operations:

- `Copy All`
- `Paste`

Given a number `n`, write a method that calculates the **fewest number of operations** needed to result in exactly `n` H characters in the file.

---

### Function Prototype

````python
def minOperations(n):
    """
    Calculates the minimum number of operations to reach n H characters
    Returns an integer
    If n is impossible to achieve, returns 0
    """

Directory Structure
holbertonschool-interview/
└── minimum_operations/
    ├── 0-minoperations.py
    ├── 0-main.py
    └── README.md
