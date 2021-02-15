// Source : https://leetcode.com/problems/maximum-subarray
// Author : xjliang
// Date   : 2021-02-15

/***************************************************************************************************** 
 *
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which 
 * has the largest sum and return its sum.
 * 
 * Example 1:
 * 
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * Example 2:
 * 
 * Input: nums = [1]
 * Output: 1
 * 
 * Example 3:
 * 
 * Input: nums = [0]
 * Output: 0
 * 
 * Example 4:
 * 
 * Input: nums = [-1]
 * Output: -1
 * 
 * Example 5:
 * 
 * Input: nums = [-100000]
 * Output: -100000
 * 
 * Constraints:
 * 
 * 	1 <= nums.length <= 3 * 104
 * 	-105 <= nums[i] <= 105
 * 
 * Follow up: If you have figured out the O(n) solution, try coding another solution using the divide 
 * and conquer approach, which is more subtle.
 ******************************************************************************************************/

// dp
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    
    const int n = nums.size();
    std::vector<int> dp(n);
    dp[0] = nums[0];
    int result = dp[0];
    for (int i = 1; i < n; i++) {
      dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
      result = std::max(result, dp[i]);
    }
    return result;
  }
};

// compressed dp
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    
    const int n = nums.size();    
    int dp_0 = nums[0];
    int dp_1 = 0;
    int result = dp_0;
    for (int i = 1; i < n; i++) {
      dp_1 = std::max(dp_0 + nums[i], nums[i]);
      dp_0 = dp_1;
      result = std::max(result, dp_1);
    }
    return result;
  }
};
