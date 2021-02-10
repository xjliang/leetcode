// Source : https://leetcode.com/problems/subsets
// Author : xjliang
// Date   : 2021-02-10

/***************************************************************************************************** 
 *
 * Given an integer array nums of unique elements, return all possible subsets (the power set).
 * 
 * The solution set must not contain duplicate subsets. Return the solution in any order.
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * Example 2:
 * 
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 * Constraints:
 * 
 * 	1 <= nums.length <= 10
 * 	-10 <= nums[i] <= 10
 * 	All the numbers of nums are unique.
 ******************************************************************************************************/

class Solution {
  std::vector<std::vector<int>> result;
 public:
  vector<vector<int>> subsets(vector<int>& nums) {    
    std::vector<int> track;
    backtrack(nums, track, 0);
    return result;
  }
  
  void backtrack(const std::vector<int>& nums, std::vector<int>& track,
                int curr) {
    if (curr == nums.size()) {
      result.push_back(track);
      return ;
    }
    
    // #1: not add current to track
    backtrack(nums, track, curr + 1);
    // #2: add current to track
    track.push_back(nums[curr]);
    backtrack(nums, track, curr + 1);
    track.pop_back();
  }
};
