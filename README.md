# N-Puzzle using A\* algorithm

The goal of this project is to solve the N-puzzle game using the A\* search algorithm.
We start with a square board made up of N\*N cells. One of these cells will be empty, the others will contain numbers, starting from 1, that will be unique in this instance of the puzzle. Our search algorithm will have to find a valid sequence of moves in order to reach the final state, a.k.a the "snail solution", which depends on the size of the puzzle

It is developed in C++ for Linux environment (tested on Ubuntu 20.04 and Xubuntu 18.04)

## A\*

A\* is a graph traversal and path search algorithm. It will find the shorest path between two points. In this project, we use it to find the path between two states: the state of the grid given as input (or generated) at the begining of the program, and the goal state wich is the resolved grid.

## Heuristics

A\* algorithm uses a heuristic function which calculates a theoric cost to go from the actual state to the goal state. All heuristics used in this project are admissible, i.e. they never overestimate the cost of reaching the goal.
In this project we implement the following heuristic functions:

### Hamming

This heuristic counts all the misplaced tiles on a state, compared to the goal state.

### Manhattan distance

This algorithm does the addition of the moves from all misplaced tiles to their goal place, without taking into account the tiles on their way.

### Linear Conflicts

This algorithm calculates the Manhattan Distance of each tile (the number of moves in the path from a tile to its goal), and adds the number of conflicts that may appear on that path.

Two tiles A and B are in linear conflict if :
 - they are on the same line
 - their goal positions also are on this line
 - A is to the right of B, and the goal position of A is to the left of the goal position of B.

For each line and column of the grid, we look for tiles in conflict, and add a cost of 2 for each conflicting pair.

When 3 or more tiles are in linear conflict, we pick the tile involved in the most conflicts to move first. This way we can minimize the number of additional moves, and the heuristic stays admissible.

# Performance

This project is fast on 3x3 size puzzle. However, performance will decrease quickly with more complicated map (size 4, 5...) and with a higher degree of randomization of the starting puzzle state.


# Run

```
make
./n-puzzle -h
```

To read a puzzle from a file (see help for the right input file format):
```
make
./n-puzzle -f tests/grid.3
```

To let the program generate a random puzzle (size 3x3):
```
make
./n-puzzle -g 3
```

# Authors

MrgxF
jdugoudr
