// Source : https://leetcode.com/problems/search-in-rotated-sorted-array
// Author : xjliang
// Date   : 2021-02-12

/***************************************************************************************************** 
 *
 * You are given an integer array nums sorted in ascending order (with distinct values), and an 
 * integer target.
 * 
 * Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might 
 * become [4,5,6,7,0,1,2]).
 * 
 * If target is found in the array return its index, otherwise, return -1.
 * 
 * Example 1:
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * Example 2:
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * Example 3:
 * Input: nums = [1], target = 0
 * Output: -1
 * 
 * Constraints:
 * 
 * 	1 <= nums.length <= 5000
 * 	-104 <= nums[i] <= 104
 * 	All values of nums are unique.
 * 	nums is guaranteed to be rotated at some pivot.
 * 	-104 <= target <= 104
 ******************************************************************************************************/

class Solution {
public:
  int search(const std::vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < nums[hi]) {
        if (nums[mid] < target && nums[hi] >= target) {
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
      } else {
        if (nums[lo] <= target && nums[mid] > target) {
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }
    }
    return -1;
  }
};
