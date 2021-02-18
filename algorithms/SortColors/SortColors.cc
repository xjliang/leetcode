// Source : https://leetcode.com/problems/sort-colors
// Author : xjliang
// Date   : 2021-02-18

/***************************************************************************************************** 
 *
 * Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects 
 * of the same color are adjacent, with the colors in the order red, white, and blue.
 * 
 * We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
 * 
 * Example 1:
 * Input: nums = [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * Example 2:
 * Input: nums = [2,0,1]
 * Output: [0,1,2]
 * Example 3:
 * Input: nums = [0]
 * Output: [0]
 * Example 4:
 * Input: nums = [1]
 * Output: [1]
 * 
 * Constraints:
 * 
 * 	n == nums.length
 * 	1 <= n <= 300
 * 	nums[i] is 0, 1, or 2.
 * 
 * Follow up:
 * 
 * 	Could you solve this problem without using the library's sort function?
 * 	Could you come up with a one-pass algorithm using only O(1) constant space?
 ******************************************************************************************************/

class Solution {
 public:
  void sortColors(std::vector<int>& nums) {
    int lo = 0;
    int mid = 0;
    int hi = nums.size() - 1;
    while (mid <= hi) {
      if (nums[mid] == 1) {
        mid++;
      } else if (nums[mid] == 0) {
        std::swap(nums[lo], nums[mid]);
        lo++; 
        mid++;  
      } else if (nums[mid] == 2) {
        std::swap(nums[mid], nums[hi]);
				// note here, left side of mid, everything is sorted, while right side is not
				// so we can not increment mid when mid == 2
        //mid++;
        hi--;
      }
    }
  }
};
