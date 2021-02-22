// Source : https://leetcode.com/problems/unique-binary-search-trees
// Author : xjliang
// Date   : 2021-02-22

/*****************************************************************************************************
 *
 * Given an integer n, return the number of structurally unique BST's (binary search trees) which has
 * exactly n nodes of unique values from 1 to n.
 *
 * Example 1:
 *
 * Input: n = 3
 * Output: 5
 *
 * Example 2:
 *
 * Input: n = 1
 * Output: 1
 *
 * Constraints:
 *
 * 	1 <= n <= 19
 ******************************************************************************************************/

// Taking 1 ~ n as root respectively:
//   1 as root:  # of trees = F(0) * F(n-1), F(0) = 1
//   2 as root:  # of trees = F(1) * F(n-2), F(1) = 1
//   3 as root:  # of trees = F(2) * F(n-3)
//   ...
//   n-1 as root:  # of trees = F(n-2) * F(1)
//   n as root:    # of trees = F(n-1) * F(0)
//
// So the formulation is:
//   F(n) = F(0) * F(n-1)
//        + F(1) * F(n-2)
//        + F(2) * F(n-3)
//        + ...
//        + F(n-2) * F(1)
//        + F(n-1) * F(0)
class Solution {
 public:
  int numTrees(int n) {
    std::vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        dp[i] += dp[j - 1] * dp[i - j];
      }
    }
    return dp[n];
  }
};
