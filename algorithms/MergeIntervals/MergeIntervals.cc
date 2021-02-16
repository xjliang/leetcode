// Source : https://leetcode.com/problems/merge-intervals
// Author : xjliang
// Date   : 2021-02-16

/***************************************************************************************************** 
 *
 * Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
 * and return an array of the non-overlapping intervals that cover all the intervals in the input.
 * 
 * Example 1:
 * 
 * Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
 * 
 * Example 2:
 * 
 * Input: intervals = [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * Constraints:
 * 
 * 	1 <= intervals.length <= 104
 * 	intervals[i].length == 2
 * 	0 <= starti <= endi <= 104
 ******************************************************************************************************/

class Solution {
 public:
  std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
    std::vector<std::vector<int>> result;
    if (intervals.empty()) {
      return result;
    }

    std::sort(intervals.begin(), intervals.end(),
              [](const std::vector<int>& lhs, const std::vector<int>& rhs) {
      return lhs[0] < rhs[0] || (lhs[0] == rhs[0] && lhs[1] > rhs[1]);
    });

    result.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
      const std::vector<int>& curr = intervals[i];
      std::vector<int>& last = result.back();
      if (curr[0] <= last[1]) {
        last[1] = std::max(last[1], curr[1]);
      } else {
        result.push_back(curr);
      }
    }
    return result;
  }
};

