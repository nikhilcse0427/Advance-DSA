// You’re given an N x N maze.
// The rat starts at the top-left cell (0, 0) and needs to reach the bottom-right cell (N-1, N-1).
// The maze has:
// 0 → open path
// 1 → wall/block
// The rat can move in one or more directions (commonly: Down, Right, sometimes Left and Up too).
// Find all possible paths (or check if at least one exists).


#include <iostream>
#include <vector>
using namespace std;

// Global maze and path counter
vector<vector<int>> maze;
int numOfPath = 0;

// Checks if the current position is valid and open
bool canWeGo(int i, int j, int n, vector<vector<int>> &maze) {
  return (i >= 0 && j >= 0 && i < n && j < n && maze[i][j] == 0);
}

// Recursive backtracking function to explore all paths
void path(int i, int j, int n, vector<vector<int>> &maze) {
  if (i == n - 1 && j == n - 1) {
    numOfPath++;
    return;
  }

  maze[i][j] = 2; // 🔧 FIXED: Mark the cell as visited (this was correct)

  // LEFT
  if (canWeGo(i, j - 1, n, maze)) {
    path(i, j - 1, n, maze);
  }

  // RIGHT
  if (canWeGo(i, j + 1, n, maze)) {
    path(i, j + 1, n, maze);
  }

  // UP
  if (canWeGo(i - 1, j, n, maze)) {
    path(i - 1, j, n, maze);
  }

  // DOWN
  if (canWeGo(i + 1, j, n, maze)) {
    path(i + 1, j, n, maze);
  }

  maze[i][j] = 0; // 🔧 FIXED: Reset visited cell when backtracking
}

int main() {
  maze = {
    {0, 0, 0, 0, 1, 0, 0},
    {1, 1, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 0}
  };

  path(0, 0, maze.size(), maze);  // 🔧 FIXED: Use maze.size() instead of hardcoded value (7)
  cout << "Total paths: " << numOfPath << endl;  // 🆗 Output the final result
  return 0;
}