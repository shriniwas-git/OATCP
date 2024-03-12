Base Cases:
Out of Bounds or Blocked Cell:

If the current row or column indices are out of bounds (less than 0 or greater than or equal to n), or if the current cell is blocked ('*'), it's not possible to proceed further from this cell. Therefore, return 0 to indicate that there are no valid paths from this cell.
Bottom-Right Cell:

If the current indices (ind1 and ind2) reach the bottom-right cell (which is at the coordinates (n-1, n-1)), it means we have reached the destination. Return 1 to indicate that there is one valid path from the top-left cell to the bottom-right cell.
Memoization Check:

Before proceeding with the recursion, check if the result for the current cell (specified by indices ind1 and ind2) has already been computed and stored in the memoization table dp. If so, return the stored value from dp[ind1][ind2] to avoid redundant computations.
Recursion:
Move Down:

Recursively call the func function with the incremented row index (ind1 + 1), the same column index (ind2), and other parameters. This represents moving down in the grid.
Move Right:

Recursively call the func function with the same row index (ind1) and the incremented column index (ind2 + 1), along with other parameters. This represents moving right in the grid.
Memoization:
After calculating the number of paths from down and right, store the sum of these paths in the memoization table dp at the current cell's position dp[ind1][ind2]. This allows us to reuse the computed values for future recursive calls at the same cell, avoiding redundant calculations.
Return:
Return the sum of paths from moving down and moving right. This sum represents the total number of valid paths from the current cell to the bottom-right cell in the grid.