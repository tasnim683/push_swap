*This project has been created as part of the 42 curriculum by tamakhlo, nmokashi.*

# Push_swap

## Description

`push_swap` is a 42 project focused on sorting a stack of integers using a restricted set of operations and producing the smallest or most efficient sequence of operations possible.

The program works with two stacks:

- **Stack A**: contains the input integers.
- **Stack B**: initially empty and used as auxiliary storage.

The available operations are:

- `sa` / `sb` — swap the first two elements of stack A / B
- `ss` — `sa` and `sb` simultaneously
- `pa` / `pb` — push the top element from one stack to the other
- `ra` / `rb` — rotate a stack upwards
- `rr` — `ra` and `rb` simultaneously
- `rra` / `rrb` — reverse rotate a stack
- `rrr` — `rra` and `rrb` simultaneously

The project implements several sorting strategies and can either use a specific algorithm or automatically choose an algorithm according to the disorder of the input.

The main algorithms are:

1. **MinMax sorting** — designed for simple/small or relatively ordered inputs.
2. **Medium chunk-based sorting** — divides the input into chunks and processes them efficiently.
3. **Radix sort** — uses binary representation and is designed for large/complex inputs.
4. **Adaptive sorting** — measures the disorder of the input and automatically selects one of the three algorithms.

The program also includes:

- Input validation and integer overflow checking
- Duplicate detection
- Algorithm-selection flags
- Operation counting
- Disorder measurement
- Benchmark output
- Value mapping/ranking for radix sort
- Memory allocation checks

---

## Algorithms

### 1. MinMax Algorithm

The MinMax algorithm repeatedly finds the **minimum value** in Stack A and moves it to Stack B.

Instead of blindly rotating in one direction, the algorithm checks the position of the minimum:

- If the minimum is in the first half of Stack A, it uses `ra`.
- If the minimum is in the second half, it uses `rra`.

This minimizes the number of rotations needed to bring the minimum to the top.

Once only three elements remain in Stack A, they are sorted using a dedicated `sort_three()` function.

Finally, all elements in Stack B are pushed back to Stack A using `pa`.

#### Flow

```text
             Stack A
                |
                v
       Find minimum position
                |
        +-------+-------+
        |               |
     First half      Second half
        |               |
       ra              rra
        |               |
        +-------+-------+
                |
                v
          Minimum on top
                |
                v
               pb
                |
                v
      Repeat until 3 remain
                |
                v
           Sort 3 elements
                |
                v
       Push everything back
             with pa
                |
                v
          Sorted Stack A
```

The main utility functions are:

- `find_min_position()` — finds where the minimum value is.
- `sort_three()` — handles the final three elements.
- `minmax()` — coordinates the complete algorithm.

The approximate complexity is **O(n²)**.

---

### 2. Medium Algorithm — Chunk-Based Sorting

The medium algorithm divides the sorted values into smaller groups called **chunks**.

First, a copy of Stack A is created and sorted. This sorted array is not used as a stack; it is used as a reference to determine which chunk each value belongs to.

The chunk size is calculated using:

```text
sqrt(n)
```

For example, for approximately 100 elements:

```text
sqrt(100) = 10
```

So the values are processed in chunks of roughly 10 elements.

#### Medium algorithm structure

```text
                  medium_sort()
                       |
                       v
             create_sorted_array()
                       |
                       v
                get_chunk_size()
                    sqrt(n)
                       |
                       v
              Calculate # chunks
                       |
                       v
             Start with last chunk
                       |
                       v
                push_chunk()
                       |
          +------------+------------+
          |                         |
     value belongs             value does not
     to current chunk          belong to chunk
          |                         |
          v                         v
         pb                         ra
          |                         |
          +------------+------------+
                       |
                       v
              Next chunk
                       |
                       v
              Repeat until B
               contains all
                       |
                       v
             find maximum in B
                       |
                       v
          Rotate shortest direction
                       |
                       v
                      pa
                       |
                       v
              Repeat until B empty
                       |
                       v
                Sorted Stack A
```

The main utilities are:

#### `create_sorted_array()`

Creates a copy of Stack A and sorts the copy using bubble sort.

The original stack is not modified by this operation.

#### `get_chunk_size()`

Calculates:

```text
sqrt(size)
```

This determines approximately how many elements belong to each chunk.

#### `get_chunk()`

Looks for a value inside the sorted array.

Its position determines its chunk:

```text
chunk = position / chunk_size
```

#### `push_chunk()`

Checks the top element of Stack A.

If it belongs to the current chunk:

```text
pb
```

Otherwise:

```text
ra
```

This gradually moves the current chunk into Stack B.

#### `find_max_position()`

Searches Stack B for the largest value.

#### `push_max_back()`

Once the elements are in Stack B, the algorithm finds the maximum and chooses the shortest way to bring it to the top:

```text
          Maximum position
                 |
        +--------+--------+
        |                 |
     First half       Second half
        |                 |
       rb                rrb
        |                 |
        +--------+--------+
                 |
                 v
                pa
```

This reconstructs Stack A in ascending order.

The approximate complexity is **O(n × sqrt(n))**.

---

### 3. Complex Algorithm — Radix Sort

For large and highly disordered inputs, the project uses **Radix Sort**.

Radix sort processes numbers bit by bit instead of comparing the values directly.

Before sorting, the values are mapped to their **rank** in the sorted order.

For example:

```text
Original:

50  10  80  30

Sorted:

10  30  50  80

Ranks:

50 -> 2
10 -> 0
80 -> 3
30 -> 1
```

This is useful because radix sort works with non-negative integer ranks.

#### Radix flow

```text
              Original values
                     |
                     v
                map_values()
                     |
                     v
              Convert values
               to their ranks
                     |
                     v
             Determine number
                of max bits
                     |
                     v
              Process bit 0
                     |
          +----------+----------+
          |                     |
        bit = 0               bit = 1
          |                     |
          v                     v
         pb                    ra
          |                     |
          +----------+----------+
                     |
                     v
          Push everything back
                 with pa
                     |
                     v
              Process next bit
                     |
                     v
                  repeat
                     |
                     v
              Sorted Stack A
```

For every bit:

- If the current bit is `0`, the value is pushed to Stack B using `pb`.
- If the current bit is `1`, the value stays in Stack A and is rotated using `ra`.
- At the end of the bit pass, everything in B is returned to A using `pa`.

The algorithm continues until all significant bits have been processed.

The approximate complexity is **O(n log n)**.

---

## Adaptive Algorithm

The adaptive algorithm is the default strategy.

Instead of always using the same sorting algorithm, it first measures how disordered Stack A is.

The program calculates the number of **inversions**.

An inversion exists when:

```text
i < j
and
A[i] > A[j]
```

For example:

```text
1 3 2
```

contains one inversion:

```text
3 > 2
```

The maximum possible number of inversions for `n` elements is:

```text
n * (n - 1) / 2
```

The project normalizes the number of inversions to obtain a disorder value between `0` and `1`.

```text
disorder =
    inversions / maximum_inversions
```

The adaptive strategy then chooses:

```text
disorder < 0.2
        |
        v
     MINMAX

0.2 <= disorder < 0.5
        |
        v
     MEDIUM

disorder >= 0.5
        |
        v
      RADIX
```

#### Adaptive decision map

```text
                         Input
                           |
                           v
                   Measure disorder
                           |
                           v
                 +---------+---------+
                 |                   |
              < 0.2              >= 0.2
                 |                   |
                 v                   v
              MINMAX              >= 0.5 ?
                                     |
                         +-----------+-----------+
                         |                       |
                        NO                      YES
                         |                       |
                         v                       v
                      MEDIUM                   RADIX
```

The user can also explicitly select an algorithm using the available flags.

---

## Flags

The project supports algorithm-selection options:

```text
--simple
--medium
--complex
--adaptive
```

Their meaning is:

| Flag | Algorithm |
|---|---|
| `--simple` | MinMax |
| `--medium` | Chunk-based Medium |
| `--complex` | Radix Sort |
| `--adaptive` | Automatically chooses the algorithm |

The default mode is:

```text
--adaptive
```

The project also supports:

```text
--bench
```

which enables benchmark information.

Example:

```bash
./push_swap --simple 4 2 3 1
./push_swap --medium 10 3 8 1 5
./push_swap --complex 10 3 8 1 5
./push_swap --adaptive 10 3 8 1 5
./push_swap --bench --adaptive 10 3 8 1 5
```

---

## Benchmark

The benchmark mode provides information about the execution.

It reports:

- Input disorder
- Selected strategy
- Estimated algorithm complexity
- Total number of operations
- Number of each individual operation

The operations counted are:

```text
sa  sb  ss
pa  pb
ra  rb  rr
rra rrb rrr
```

The benchmark therefore makes it possible to compare the behaviour of the different strategies.

Example structure:

```text
[bench] Disorder: ...
[bench] Strategy: ...
[bench] Total operations: ...

sa: ... sb: ... ss: ... pa: ... pb: ... ra: ...
rb: ... rr: ... rra: ... rrb: ... rrr: ...
```

Benchmark information is printed to **file descriptor 2 (stderr)** so that the generated push_swap operations remain separate from the benchmark output.

---

## Input Validation and Error Handling

Before sorting, the program validates the input.

### Invalid numbers

The program checks that every argument represents a valid integer.

Accepted forms include:

```text
42
-42
+42
```

Invalid examples include:

```text
abc
12a
+
-
```

### Integer overflow

The program checks that every number fits inside the signed 32-bit integer range:

```text
-2147483648
to
2147483647
```

If an overflow is detected, the program prints:

```text
Error
```

and exits.

### Duplicate values

`check_duplicates()` compares every pair of values.

If two values are equal:

```text
Error
```

is printed and the program exits.

### Already sorted input

Before running a sorting algorithm, the program checks whether Stack A is already sorted.

If it is already sorted, no operations are performed.

---

## Technical Choices

### Array-based stacks

The project represents both stacks using dynamically allocated arrays.

The stack structure stores:

```text
a       -> Stack A
b       -> Stack B
size_a  -> number of elements in A
size_b  -> number of elements in B
bench   -> benchmark counters
```

This allows the operations to manipulate the stacks directly.

### Sorted reference array

The medium algorithm creates a separate sorted copy of the input.

This allows the program to determine:

- the relative order of each value
- which chunk a value belongs to
- where the maximum value is

without modifying the original stack while preparing the algorithm.

### Value mapping

Radix sort requires values that can be processed as non-negative ranks.

`map_values()` creates a sorted copy and replaces every original value by its position in that sorted array.

For example:

```text
Input:
40 10 30 20

Mapped:
3  0  2  1
```

The relative ordering is preserved while making the numbers suitable for radix sort.

---

## Core Operations

The project implements the complete push_swap operation set.

### Push

`pa` - Moves the top element from B to A.
`pb` - Moves the top element from A to B.

### Swap

`sa` - Swaps the first two elements of A.
`sb` - Swaps the first two elements of B.
`ss` - Performs `sa` and `sb`.

### Rotate

`ra` - Moves the first element of A to the bottom.
`rb` - Moves the first element of B to the bottom.
`rr` - Performs `ra` and `rb`.
`rra` - Moves the last element of A to the top.
`rrb` - Moves the last element of B to the top.
`rrr` - Performs `rra` and `rrb`.

All operations also update the benchmark counters when appropriate.

---

## Instructions

The project is compiled using the provided `Makefile`.

Build the project with:

```bash
make
```

Clean object files:

```bash
make clean
```

Remove object files and the executable:

```bash
make fclean
```

Recompile from scratch:

```bash
make re
```

The project is compiled with strict compiler flags:

```text
-Wall -Wextra -Werror
```

and uses the project's `libft` and `ft_printf` libraries.

---

Basic execution:

```bash
./push_swap 2 1 3
```

The program outputs the sequence of operations required to sort Stack A.

Using a specific algorithm:

```bash
./push_swap --simple 4 2 3 1
./push_swap --medium 4 2 3 1
./push_swap --complex 4 2 3 1
./push_swap --adaptive 4 2 3 1
```

Benchmark mode:

```bash
./push_swap --bench --adaptive 4 2 3 1
```

---

## Project Structure

The project can be understood as several layers:

```text
                         push_swap
                             |
             +---------------+---------------+
             |                               |
        Input layer                    Sorting layer
             |                               |
     +-------+-------+             +---------+---------+
     |       |       |             |         |         |
  Parsing  Errors  Duplicates    MinMax   Medium    Radix
                                     \       |       /
                                      \      |      /
                                       +-----+-----+
                                             |
                                         Adaptive
                                             |
                                             v
                                     Stack operations
                                             |
                                             v
                                     pa/pb/sa/...
                                             |
                                             v
                                         Bench
```

A simpler mental model is:

```text
INPUT
  |
  v
VALIDATE
  |
  v
MEASURE DISORDER
  |
  v
CHOOSE ALGORITHM
  |
  +----> MINMAX
  |
  +----> MEDIUM / CHUNKS
  |
  +----> RADIX
  |
  v
OPERATIONS
  |
  v
SORTED STACK A
  |
  v
BENCHMARK
```

---

## Complexity Summary

| Strategy | Main idea | Approximate complexity |
|---|---|---|
| MinMax | Repeatedly extract minimum | O(n²) |
| Medium | Chunk-based sorting | O(n × sqrt(n)) |
| Complex | Binary Radix Sort | O(n log n) |
| Adaptive | Chooses based on disorder | Depends on selected strategy |

The adaptive algorithm does not have one fixed complexity because its complexity depends on the algorithm selected from the measured disorder.

---

## Contributions

The project was developed collaboratively by:

- **nmokashi**
- **tamakhlo**

The work was divided according to the major parts of the project.

### nmokashi

Responsible mainly for the first half of the project and the foundational components:

- First half of the push_swap operations
- MinMax algorithm
- Complex algorithm / Radix Sort
- Argument parsing
- Flags
- Input validation
- Norminette checking
- Testing

### tamakhlo

Responsible mainly for the second half and the adaptive/benchmarking components:

- Second half of the push_swap operations
- Medium / chunk-based algorithm
- Adaptive algorithm
- Error handling
- Disorder measurement
- Benchmark system
- README/documentation
- Testing

### Shared Work

Both learners contributed to:

- Testing
- Debugging
- Integration
- Reviewing each other's code
- Benchmark system
- Making sure the different algorithms work together
- Final project validation

---

## Resources

The following types of resources were used during development:

- **42 `push_swap` subject** — project requirements, allowed operations and expected behaviour.
- **C language documentation** — memory allocation, arrays, pointers, structures and standard C concepts.
- **Sorting algorithm references** — concepts behind MinMax-style sorting, chunk-based sorting and Radix Sort.
- **Mathematical references** — square root, inversion counting and complexity analysis.
- **42 Norminette documentation** — coding-style and formatting requirements.
- **Project testing tools** — used to generate different input sizes and verify sorting behaviour and operation counts.
- https://github.com/abgdnv/push-swap-test - for testing push swap

### AI Usage

AI was used as a learning and development aid, not as a replacement for the implementation work.

It was mainly used for:

- Explaining C concepts and existing code.
- Helping understand the logic behind the sorting algorithms.
- Explaining algorithmic complexity.
- Helping reason about edge cases and possible bugs.
- Assisting with debugging and understanding compiler errors.
- Explaining the adaptive strategy and disorder calculation.
- Helping structure and document the project.

The actual project implementation, integration, testing and validation were performed by the learners.

---

## Conclusion

The main goal of this project was not only to sort integers, but to understand how different algorithms behave depending on the structure of the input.

The project therefore provides three different levels of sorting strategies:

```text
Simple input
     |
     v
   MinMax

Medium input
     |
     v
   Chunks

Complex input
     |
     v
   Radix
```

and combines them through the adaptive strategy:

```text
              INPUT
                |
                v
          Measure disorder
                |
       +--------+--------+
       |        |        |
      Low    Medium     High
       |        |        |
       v        v        v
    MinMax   Medium     Radix
       |        |        |
       +--------+--------+
                |
                v
          Sorted Stack A
```

This structure allows the project to demonstrate different algorithmic approaches while also providing a way to measure and compare their performance.
