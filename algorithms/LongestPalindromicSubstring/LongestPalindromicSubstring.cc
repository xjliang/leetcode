// Source : https://leetcode.com/problems/longest-palindromic-substring
// Author : xjliang
// Date   : 2021-02-01

/***************************************************************************************************** 
 *
 * Given a string s, return the longest palindromic substring in s.
 * 
 * Example 1:
 * 
 * Input: s = "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * Example 2:
 * 
 * Input: s = "cbbd"
 * Output: "bb"
 * 
 * Example 3:
 * 
 * Input: s = "a"
 * Output: "a"
 * 
 * Example 4:
 * 
 * Input: s = "ac"
 * Output: "a"
 * 
 * Constraints:
 * 
 * 	1 <= s.length <= 1000
 * 	s consist of only digits and English letters (lower-case and/or upper-case),
 ******************************************************************************************************/

// 双指针
class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.empty()) {
      return "";
    }
     
    int start = 0;
    int max_len = 1;
    for (int i = 0; i < s.size(); i++) {
      int len1 = expand(s, i, i);
      int len2 = expand(s, i, i + 1);
      int len = std::max(len1, len2);
      // update result
      if (len > max_len) {
        start = i - (len - 1) / 2;  // 这里要注意 len - 1
        max_len = len;
      }
    }
    return s.substr(start, max_len);
  }
  
 private:
  int expand(const std::string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      left--;
      right++;
    }
    // 原本应该是 right - left + 1，因为在上面 left 和 right 都扩展了
    // 这里反而要 -1
    return right - left - 1;
  }
};

// 动态规划
class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.empty()) {
      return "";
    }
    
    int n = s.size();
    std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
    // base case
    for (int i = 0; i < n; i++) {
      dp[i][i] = true;
    }
    int start = 0;
    int max_len = 1;
	// 注意循环遍历的方向：自下而上，从左到右
    for (int i = n - 2; i >= 0; i--) {
      for (int j = i + 1; j < n; j++) {
        if (s[i] == s[j]) {
		  // 若两个字符相邻或者它们之间的子串是回文，则该子串也是回文
          if (j - i == 1 || dp[i + 1][j - 1]) {
            dp[i][j] = true;
          }
        }
        // update result
        if (dp[i][j] && j - i + 1 > max_len) {
          start = i;
          max_len = j - i + 1;
        }
      }
    }
    return s.substr(start, max_len);
  }
};
