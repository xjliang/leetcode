// Source : https://leetcode.com/problems/maximal-rectangle
// Author : xjliang
// Date   : 2021-02-21

/*****************************************************************************************************
 *
 * Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing
 * only 1's and return its area.
 *
 * Example 1:
 *
 * Input: matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * Output: 6
 * Explanation: The maximal rectangle is shown in the above picture.
 *
 * Example 2:
 *
 * Input: matrix = []
 * Output: 0
 *
 * Example 3:
 *
 * Input: matrix = [["0"]]
 * Output: 0
 *
 * Example 4:
 *
 * Input: matrix = [["1"]]
 * Output: 1
 *
 * Example 5:
 *
 * Input: matrix = [["0","0"]]
 * Output: 0
 *
 * Constraints:
 *
 * 	rows == matrix.length
 * 	cols == matrix.length
 * 	0 <= row, cols <= 200
 * 	matrix[i][j] is '0' or '1'.
 ******************************************************************************************************/

// monotonic statc
// related with https://leetcode.com/problems/largest-rectangle-in-histogram/
class Solution {
public:
  int maximalRectangle(const std::vector<std::vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return 0;
    }

    const int m = matrix.size();
    const int n = matrix[0].size();
    std::vector<int> heights(n + 2, 0);
    int result = 0;
    for (int row = 0; row < m; row++) {
      for (int col = 0; col < n; col++) {
        if (matrix[row][col] == '1') {
          heights[col + 1] += 1;
        } else {
          heights[col + 1] = 0;
        }
      }

      // find largest rectangle in histogram
      std::stack<int> stk;
      stk.push(0);
      for (int i = 1; i < n + 2; i++) {
        while (heights[i] < heights[stk.top()]) {
          int h = heights[stk.top()];
          stk.pop();
          int w = i - stk.top() - 1;
          result = std::max(result, w * h);
        }
        stk.push(i);
      }
    }
    return result;
  }
};

// we start from the first row, and move downward;
// height[i] record the current number of continuous '1' in column i;
// left[i] record the left most index j which satisfies that for any index k
//   from j to i, height[k] >= height[i];
// right[i] record the right most index j which satisfies that for any index k
//   from j to i, height[k] <= height[i];
// finally, we can update the max area with value height[i] * (right[i] -
//   left[i]  + 1);
class Solution {
public:
  int maximalRectangle(const std::vector<std::vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return 0;
    }

    const int m = matrix.size();
    const int n = matrix[0].size();
    std::vector<int> left(n, 0);
    std::vector<int> right(n, n);
    std::vector<int> height(n, 0);
    int result = 0;
    for (int i = 0; i < m; i++) {
      // update height
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == '1') {
          height[j]++;
        } else {
          height[j] = 0;
        }
      }

      // update from left to right
      int left_bound = 0;
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == '1') {
          left[j] = std::max(left[j], left_bound);
        } else {
          left[j] = 0;
          left_bound = j + 1;
        }
      }

      // update right from right to left
      int right_bound = n - 1;
      for (int j = n - 1; j >= 0; j--) {
        if (matrix[i][j] == '1') {
          right[j] = std::min(right[j], right_bound);
        } else {
          right[j] = n - 1;
          right_bound = j - 1;
        }
      }

      // update result
      for (int j = 0; j < n; j++) {
        result = std::max(result, (right[j] - left[j] + 1) * height[j]);
      }
    }
    return result;
  }
};
