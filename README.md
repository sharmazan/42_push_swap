*This project has been created as part of the 42 curriculum by __ssharmaz__*.

# Description

The project's goal is to learn about sorting algorithms and complexity.
The program should take some random integers without duplicates as an input, save it into the stack A, and output instructions to sort the stack using additional stack B and commands:
- sa (swap a): Swap the first 2 elements at the top of stack a.
- sb (swap b): Swap the first 2 elements at the top of stack b.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a.
- pb (push b): Take the first element at the top of a and put it at the top of b.
- ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time.

# Instructions

## How to run
Make first:
```
make
```
then run with
```
./push_swap 1 5 2 ... -100 325
```
or 
```
./push_swap "1 5 2 ... -100 325"
```

Do not provide duplicates or numbers that are not inside the int limits as arguments. 

# Resources

For sorting stack Radix sort is used:
https://en.wikipedia.org/wiki/Radix_sort
