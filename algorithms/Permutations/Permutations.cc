// Source : https://leetcode.com/problems/permutations
// Author : xjliang
// Date   : 2021-02-10

/***************************************************************************************************** 
 *
 * Given an array nums of distinct integers, return all the possible permutations. You can return the 
 * answer in any order.
 * 
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Example 2:
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * Example 3:
 * Input: nums = [1]
 * Output: [[1]]
 * 
 * Constraints:
 * 
 * 	1 <= nums.length <= 6
 * 	-10 <= nums[i] <= 10
 * 	All the integers of nums are unique.
 ******************************************************************************************************/

class Solution {
  std::vector<std::vector<int>> result;
 public:
  vector<vector<int>> permute(const vector<int>& nums) {
    std::vector<int> track;
    backtrack(nums, track);
    return result;
  }
  
  void backtrack(const std::vector<int>& nums, std::vector<int>& track) {
    if (track.size() == nums.size()) {
      result.push_back(track);
      return;
    }
    
    for (int item : nums) {
      if (VectorContains(track, item)) {
        continue;
      }
      track.push_back(item);
      backtrack(nums, track);
      track.pop_back();
    }
  }
  
  bool VectorContains(const std::vector<int>& nums, int item) {
    for (int i : nums) {
      if (i == item) {
        return true;
      }
    }
    return false;
  }
};
