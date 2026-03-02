# TODO

- Verify arguments and exit with printing Error if any:
--- DONE some arguments not being integers
--- DONE some arguments exceeding the integer limits
--- the presence of duplicates.
--- Analyze also "a b c" format of arguments

Do the ps_helper functions:
pb, pa, rb, ra

Implement Radix:
- Store numbers to an array, replace them with indexes from 0.
- Sort the stack bit by bit:
--- set n to bits in max_index
--- if the n bit is "0": pb, else ra
--- return all elements from B to A
--- decrease n and repeat

- Fill the README.md according to the Requirements

## Allowed external functions:
read, write, malloc, free, exit
