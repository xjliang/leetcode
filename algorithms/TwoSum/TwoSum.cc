// Source : https://leetcode.com/problems/two-sum
// Author : xjliang
// Date   : 2021-02-01

/***************************************************************************************************** 
 *
 * Given an array of integers nums and an integer target, return indices of the two numbers such that 
 * they add up to target.
 * 
 * You may assume that each input would have exactly one solution, and you may not use the same 
 * element twice.
 * 
 * You can return the answer in any order.
 * 
 * Example 1:
 * 
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Output: Because nums[0] + nums[1] == 9, we return [0, 1].
 * 
 * Example 2:
 * 
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 * 
 * Example 3:
 * 
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 * 
 * Constraints:
 * 
 * 	2 <= nums.length <= 103
 * 	-109 <= nums[i] <= 109
 * 	-109 <= target <= 109
 * 	Only one valid answer exists.
 *
 ******************************************************************************************************/

// 用一个 map 记录每个数在数组的位置，若能找到剩余的值，则直接返回
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    std::unordered_map<int, int> dict;
    for (int i = 0; i < nums.size(); i++) {
      int rest = target - nums[i];
      if (dict.find(rest) == dict.end()) {
        dict[nums[i]] = i;
      } else {
        return std::vector<int>{dict[rest], i};
      }
    }
    return std::vector<int>{-1, -1};
  }
};
