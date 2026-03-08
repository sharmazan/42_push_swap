# TODO


Implement Chunking

- Fill the README.md according to the Requirements

## Allowed external functions:
read, write, malloc, free, exit


Done:
- Verify arguments and exit with printing Error if any:
--- DONE some arguments not being integers
--- DONE some arguments exceeding the integer limits
--- DONE the presence of duplicates.
--- DONE Analyze also "a b c" format of arguments

the ps_helper functions:
pb, pa, rb, ra, rra, rrb


verification for duplicates
saving numbers to an array
sorting array
search element ny value

Selection sort:
- find the lowest number with ra | rra
- pb
- repeat until there is elements in A
return all elements in A



Radix sort:
- Store numbers to an array, sort array
- Normalize: replace numbers in stackA with indexes from array
- Sort the stack bit by bit:
--- set n to bits from 0 to max_bits in max_index
--- for every value in stackA:
--- if the n bit is "0": pb, else ra
--- return all elements from B to A
--- increase n and repeat
