# Push_swap

Push_swap is a project focused on sorting a stack of integers using a limited set of operations. The objective is to sort the stack with the minimum number of moves, implementing and optimizing sorting algorithms.

## Features

- Sorting using two stacks (`a` and `b`).
- Predefined operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr`.
- Efficient sorting for both small and large data sets.

## Usage

1. Clone the repository:
	```bash
	git clone <repository_url>
	cd Push_swap
	```
2. Compile the program:
	```bash
	make
	```
3. Run the program with a list of integers:
	```bash
	./push_swap 4 67 3 87 23
	```
	or
	```bash
	./push_swap "4 67 3 87 23"
	```

## Testing

Test the program with various input cases and evaluate the number of operations used.

## Learning Objectives

- Understand and implement sorting algorithms.
- Optimize algorithms for performance.
- Work with stacks and operations.

## Sorting Process

The `push_swap` program sorts a stack of integers using two stacks (`a` and `b`) and a predefined set of operations. The goal is to minimize the number of moves required to sort the numbers. Below is an overview of the process:

### 1. Parsing and Validation

- The program starts by validating the provided arguments:
  - Ensures all numbers are valid and there are no duplicates.
  - Converts the numbers into nodes of a circular doubly linked list (`stack_a`).
- Each node is assigned an index based on the value of the number to facilitate sorting.

### 2. Chunk Division

- For larger inputs, numbers are divided into **chunks** (smaller groups) based on their indices.
- This allows the algorithm to process numbers in smaller parts, reducing complexity.

### 3. Initial Sorting

- For small stacks (≤ 5 elements):
  - The program uses `mini_sort` or `medium_sort` for direct sorting.
- For larger stacks:
  - Numbers are moved from `stack_a` to `stack_b` in chunks, prioritizing elements closer to the top or bottom of `stack_a`.

### 4. Sorting Stack `b`

- While numbers are in `stack_b`, they are reorganized to facilitate reinsertion into `stack_a`.
- The largest number in `stack_b` is moved to the top to be reinserted in the correct position in `stack_a`.

### 5. Final Adjustments

- After all numbers are moved back to `stack_a`, the program adjusts the stack to ensure the smallest number is at the top.
- This is done using the `final_adjust` function.

### 6. Operations Used

- **Swaps (`sa`, `sb`, `ss`)**: Swap the first two elements of a stack.
- **Push (`pa`, `pb`)**: Move the top element of one stack to another.
- **Rotations (`ra`, `rb`, `rr`)**: Rotate the elements of a stack upwards.
- **Reverse Rotations (`rra`, `rrb`, `rrr`)**: Rotate the elements of a stack downwards.

### 7. Optimizations

- The program combines rotations (`rr` and `rrr`) whenever possible to reduce the number of moves.
- The insertion logic calculates the optimal position to minimize unnecessary rotations.

### Execution Example

Input:
```bash
./push_swap 4 67 3 87 23
```

Output (operations performed):
```
pb
pb
ra
pb
ra
pa
pa
pa
```

Result:
```
Stack A: [3, 4, 23, 67, 87]
```
