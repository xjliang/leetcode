// Source : https://leetcode.com/problems/longest-consecutive-sequence
// Author : xjliang
// Date   : 2021-03-02

/*****************************************************************************************************
 *
 * Given an unsorted array of integers nums, return the length of the longest consecutive elements
 * sequence.
 *
 * Example 1:
 *
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
 *
 * Example 2:
 *
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 *
 * Constraints:
 *
 * 	0 <= nums.length <= 104
 * 	-109 <= nums[i] <= 109
 *
 * Follow up: Could you implement the O(n) solution?
 ******************************************************************************************************/

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    std::unordered_set<int> dict(nums.begin(), nums.end());
    int result = 0;
    for (int x : nums) {
      if (dict.find(x - 1) == dict.end()) {
        int y = x + 1;
        while (dict.find(y) != dict.end()) {
          y++;
        }
        result = std::max(result, y - x);
      }
    }
    return result;
  }
};
