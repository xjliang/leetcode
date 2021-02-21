// Source : https://leetcode.com/problems/largest-rectangle-in-histogram
// Author : xjliang
// Date   : 2021-02-21

/*****************************************************************************************************
 *
 * Given n non-negative integers representing the histogram's bar height where the width of each bar
 * is 1, find the area of largest rectangle in the histogram.
 *
 * Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
 *
 * The largest rectangle is shown in the shaded area, which has area = 10 unit.
 *
 * Example:
 *
 * Input: [2,1,5,6,2,3]
 * Output: 10
 *
 * Example 1:
 *
 * Input: heights = [2,1,5,6,2,3]
 * Output: 10
 * Explanation: The above is a histogram where width of each bar is 1.
 * The largest rectangle is shown in the red area, which has an area = 10 units.
 *
 * Example 2:
 *
 * Input: heights = [2,4]
 * Output: 4
 *
 * Constraints:
 *
 * 	1 <= heights.length <= 105
 * 	0 <= heights[i] <= 104
 ******************************************************************************************************/

// TC: O(N^2)
// SC: O(1)
// TLE!!!
class Solution {
 public:
  int largestRectangleArea(const std::vector<int>& heights) {
    if (heights.empty()) {
      return 0;
    }

    int n = heights.size();
    int result = 0;
    for (int i = 0; i < n; i++) {
      int left = i;
      while (left > 0 && heights[left - 1] >= heights[i]) {
        left--;
      }
      int right = i;
      while (right < n - 1 && heights[right + 1] >= heights[i]) {
        right++;
      }
      result = std::max(result, (right - left + 1) * heights[i]);
    }

    return result;
  }
};

// Monotonic stack
// TC: O(N)
// SC: O(N)
class Solution {
 public:
  int largestRectangleArea(const std::vector<int>& heights) {
    if (heights.empty()) {
      return 0;
    }
    
    int size = heights.size();
    int result = 0;
    std::stack<int> stk;    
    for (int i = 0; i < size; i++) {
      while (!stk.empty() && heights[i] < heights[stk.top()]) {
        int cur_height = heights[stk.top()];
        stk.pop();
        int cur_width = i;
        if (!stk.empty()) {
           cur_width = i - stk.top() - 1;
        }
        result = std::max(result, cur_width * cur_height);        
      }
      stk.push(i);
    }
    
    while (!stk.empty()) {
      int cur_height = heights[stk.top()];
      stk.pop();
      int cur_width = size;
      if (!stk.empty()) {
         cur_width = size - stk.top() - 1;
      }
      result = std::max(result, cur_width * cur_height);      
    }
    
    return result;
  }
};