// Source : https://leetcode.com/problems/minimum-path-sum/
// Author : xjliang
// Date   : 2021-02-17

/***************************************************************************************************** 
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, 
 * which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example 1:
 * 
 * Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
 * Output: 7
 * Explanation: Because the path 1 &rarr; 3 &rarr; 1 &rarr; 1 &rarr; 1 minimizes the sum.
 * 
 * Example 2:
 * 
 * Input: grid = [[1,2,3],[4,5,6]]
 * Output: 12
 * 
 * Constraints:
 * 
 * 	m == grid.length
 * 	n == grid[i].length
 * 	1 <= m, n <= 200
 * 	0 <= grid[i][j] <= 100
 ******************************************************************************************************/

// simply dp
class Solution {
 public:
  int minPathSum(const std::vector<std::vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }

    int m = grid.size();
    int n = grid[0].size();
    std::vector<std::vector<int>> dp(m, std::vector<int>(n));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < n; i++) {
      dp[0][i] = dp[0][i - 1] + grid[0][i];
    }
    for (int i = 1; i < m; i++) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }
    return dp[m - 1][n - 1];
  }
};

// compressed dp
class Solution {
 public:
  int minPathSum(const std::vector<std::vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }
    
    int m = grid.size();
    int n = grid[0].size();
    std::vector<int> dp(n);
    dp[0] = grid[0][0];
    for (int i = 1; i < n; i++) {
      dp[i] = dp[i - 1] + grid[0][i];
    }

    for (int i = 1; i < m; i++) {
      dp[0] += grid[i][0]; // note here
      for (int j = 1; j < n; j++) {    
        dp[j] = std::min(dp[j], dp[j - 1]) + grid[i][j];            
      }
    }
    return dp[n - 1];
  }
};

