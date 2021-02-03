// Source : https://leetcode.com/problems/3sum
// Author : xjliang
// Date   : 2021-02-03

/***************************************************************************************************** 
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find 
 * all unique triplets in the array which gives the sum of zero.
 * 
 * Notice that the solution set must not contain duplicate triplets.
 * 
 * Example 1:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Example 2:
 * Input: nums = []
 * Output: []
 * Example 3:
 * Input: nums = [0]
 * Output: []
 * 
 * Constraints:
 * 
 * 	0 <= nums.length <= 3000
 * 	-105 <= nums[i] <= 105
 ******************************************************************************************************/

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    
    int n = nums.size();
    std::vector<std::vector<int>> result;
    for (int i = 0; i < n; i++) {
      std::vector<std::vector<int>> tuples = twoSumTarget(nums, i + 1, -nums[i]);
      for (std::vector<int>& tuple : tuples) {
        tuple.push_back(nums[i]);
        result.push_back(tuple);
      }
      while (i < n - 1 && nums[i + 1] == nums[i]) {
        i++;
      }
    }
    return result;
  }
  
 private:
  std::vector<std::vector<int>> twoSumTarget(const std::vector<int>& nums,
                                             int start, int target) {
    std::vector<std::vector<int>> result;
    int lo = start;
    int hi = nums.size() - 1;    
    while (lo < hi) {
      int left = nums[lo];
      int right = nums[hi];
      int sum = nums[lo] + nums[hi];
      if (sum == target) {
        result.push_back({left, right});        
        while (lo < hi && nums[lo] == left) {
          lo++;
        }
        while (lo < hi && nums[hi] == right) {
          hi--;
        }
      } else if (sum < target) {
        while (lo < hi && nums[lo] == left) {
          lo++;
        }
      } else if (sum > target) {
        while (lo < hi && nums[hi] == right) {
          hi--;
        }
      }
    }
    return result;
  }
};
