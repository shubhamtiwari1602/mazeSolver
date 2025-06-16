// Maze Solver in C++ using DFS and BFS (simplified, readable version)
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

// Directions for movement: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Check if a cell is within bounds, not a wall, and not visited
bool isValid(int x, int y, int rows, int cols, const vector<vector<int>>& maze, const vector<vector<bool>>& visited) {
    return x >= 0 && y >= 0 && x < rows && y < cols && maze[x][y] == 0 && !visited[x][y];
}

// Print the path and the maze with the path marked
void printPath(const vector<pair<int, int>>& path, vector<vector<int>> maze) {
    cout << "Path found:\n";
    for (auto cell : path) {
        cout << "(" << cell.first << ", " << cell.second << ") ";
        maze[cell.first][cell.second] = 8; // Mark path with 8
    }
    cout << "\n\nMaze with path (8 = path):\n";
    for (auto& row : maze) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }
}

// DFS Helper Function
bool dfs(int x, int y, int ex, int ey, const vector<vector<int>>& maze, vector<vector<bool>>& visited, vector<pair<int, int>>& path) {
    // If we reached the destination cell, add it to the path and return true
    if (x == ex && y == ey) {
        path.push_back({x, y});
        return true;
    }

    visited[x][y] = true;
    path.push_back({x, y});

    int rows = maze.size(), cols = maze[0].size();

    // Try moving in all 4 directions from the current cell
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isValid(nx, ny, rows, cols, maze, visited)) {
            // Recursively try to reach destination from next cell
            if (dfs(nx, ny, ex, ey, maze, visited, path))
                return true;
        }
    }

    // If path not found from current cell, remove it from path (backtrack)
    path.pop_back();
    return false;
}

// DFS Path Finder Wrapper
void solveMazeDFS(vector<vector<int>> maze, pair<int, int> start, pair<int, int> end) {
    int rows = maze.size(), cols = maze[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<pair<int, int>> path; // To store the path from start to end

    // Start DFS from the starting cell
    if (dfs(start.first, start.second, end.first, end.second, maze, visited, path)) {
        printPath(path, maze);
    } else {
        cout << "No path exists using DFS.\n";
    }
}

// BFS Path Finder
void solveMazeBFS(vector<vector<int>> maze, pair<int, int> start, pair<int, int> end) {
    int rows = maze.size(), cols = maze[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<pair<int, int>>> parent(rows, vector<pair<int, int>>(cols, {-1, -1})); // For backtracking path
    queue<pair<int, int>> q;

    // Start BFS from the starting cell
    q.push(start);
    visited[start.first][start.second] = true;

    bool found = false;

    while (!q.empty()) {
        pair<int, int> current = q.front(); q.pop();

        // If destination is reached, stop BFS
        if (current == end) {
            found = true;
            break;
        }

        // Explore neighbors in 4 directions
        for (int i = 0; i < 4; i++) {
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];

            if (isValid(nx, ny, rows, cols, maze, visited)) {
                visited[nx][ny] = true;
                parent[nx][ny] = current; // Keep track of how we reached this cell
                q.push({nx, ny});
            }
        }
    }

    if (!found) {
        cout << "No path exists using BFS.\n";
        return;
    }

    // Reconstruct the path from end to start using the parent map
    vector<pair<int, int>> path;
    for (pair<int, int> at = end; at != make_pair(-1, -1); at = parent[at.first][at.second]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    printPath(path, maze);
}

int main() {
    // Sample maze (0 = open path, 1 = wall)
    vector<vector<int>> maze = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0}
    };

    pair<int, int> start = {0, 2}; // Start point (row, col)
    pair<int, int> end = {4, 4};   // End point (row, col)

    cout << "=== DFS Maze Solver ===\n";
    solveMazeDFS(maze, start, end);

    cout << "\n=== BFS Maze Solver ===\n";
    solveMazeBFS(maze, start, end);

    return 0;
}
