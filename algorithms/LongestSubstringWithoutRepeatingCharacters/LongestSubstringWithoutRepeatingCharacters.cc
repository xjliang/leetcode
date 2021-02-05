// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters
// Author : xjliang
// Date   : 2021-02-05

/***************************************************************************************************** 
 *
 * Given a string s, find the length of the longest substring without repeating characters.
 * 
 * Example 1:
 * 
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * 
 * Example 2:
 * 
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * Example 3:
 * 
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 * 
 * Example 4:
 * 
 * Input: s = ""
 * Output: 0
 * 
 * Constraints:
 * 
 * 	0 <= s.length <= 5 * 104
 * 	s consists of English letters, digits, symbols and spaces.
 ******************************************************************************************************/

// Sliding window
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {    
    std::unordered_map<int, int> map;
    int left = 0;
    int right = 0;
    int max_len = 0;
    while (right < s.size()) {
      char c = s[right];
      right++;
      map[c]++;
      
      while (map[c] > 1) {
        char d = s[left];
        left++;
        map[d]--;        
      }
      max_len = std::max(max_len, right - left);
    }
    return max_len;
  }
};
