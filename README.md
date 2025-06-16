# 🧭 Maze Solver using DFS and BFS in C++

This project demonstrates how to solve a maze using two popular algorithms: **Depth-First Search (DFS)** and **Breadth-First Search (BFS)**. The program takes a 2D grid (maze) as input where:

* `0` represents an open path
* `1` represents a wall

Users can specify any starting and ending point, not just the top-left or bottom-right.

---

## 🔍 How the Algorithms Work

### 🚀 Depth-First Search (DFS)

DFS explores as far as possible along one path before backtracking. In the context of the maze:

* We move in a direction until we either reach a dead end or the goal.
* If we reach a dead end, we backtrack and try a different direction.
* The path is stored, and whenever we backtrack, we remove the cell from the path.

> DFS is implemented using recursion.

### 🧮 Breadth-First Search (BFS)

BFS explores all neighboring cells before going deeper:

* It uses a queue to keep track of the next cell to explore.
* We mark each visited cell and store how we got there (its parent).
* When the end is found, we reconstruct the path from the end to the start using the parent information.

> BFS guarantees the shortest path in an unweighted grid.

---

## 💡 Code Explanation

### Core Components:

* `dx` and `dy`: Arrays to define movement directions (up, down, left, right).
* `isValid()`: Checks if a move is within the grid, not a wall, and not already visited.
* `printPath()`: Prints the path as a list of coordinates and marks it on a copy of the maze.

### 🧭 DFS Logic

1. Start from the given start cell.
2. Try each of the 4 directions recursively.
3. If a direction leads to the goal, return `true`.
4. If all directions fail, backtrack by removing the current cell from the path.

### 📦 BFS Logic

1. Start from the given start cell and enqueue it.
2. While the queue is not empty:

   * Dequeue the front cell.
   * Check if it is the goal.
   * If not, enqueue all valid neighbors.
   * Record how each neighbor was reached.
3. If the goal is found, backtrack using the parent array to build the path.

---

## 📌 Example Maze Input

```
0 1 0 0 0
0 1 0 1 0
0 0 0 1 0
1 1 0 1 0
0 0 0 0 0
```

Start: (0, 2)
End: (4, 4)

### 🖨️ Output Example

* List of steps from start to end.
* Maze with `8` marking the path.

---

## ✅ Why This Project

* Strengthens understanding of **graph traversal**.
* Shows **backtracking and shortest path finding**.
* Improves **problem-solving and debugging** skills.



---


