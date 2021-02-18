// Source : https://leetcode.com/problems/minimum-window-substring
// Author : xjliang
// Date   : 2021-02-18

/***************************************************************************************************** 
 *
 * Given two strings s and t, return the minimum window in s which will contain all the characters in 
 * t. If there is no such window in s that covers all characters in t, return the empty string "".
 * 
 * Note that If there is such a window, it is guaranteed that there will always be only one unique 
 * minimum window in s.
 * 
 * Example 1:
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 * Example 2:
 * Input: s = "a", t = "a"
 * Output: "a"
 * 
 * Constraints:
 * 
 * 	1 <= s.length, t.length <= 105
 * 	s and t consist of English letters.
 * 
 * Follow up: Could you find an algorithm that runs in O(n) time?
 ******************************************************************************************************/

class Solution {
 public:
  string minWindow(string s, string t) {
    std::unordered_map<char, int> need;
    std::unordered_map<char, int> window;
    int match_count = 0;
    for (char c : t) {
      need[c]++;
    }
    
    int left = 0;
    int right = 0;
    
    int start = -1;
    int len = s.size() + 1;
    while (right < s.size()) {
      char c = s[right];
      right++;
      if (need.find(c) != need.end()) {
        window[c]++;
        if (window[c] == need[c]) {
          match_count++;
        }
      }
      
      while (match_count == need.size()) {
        if (right - left < len) {
          start = left;
          len = right - left;
        }
        
        char d = s[left];
        left++;
        if (window.find(d) != window.end()) {
          if (window[d] == need[d]) {
            match_count--;
          }
          window[d]--;
        }
      }
    }
    return (start == -1 ? "" : s.substr(start, len));
  }
};

// quicker one
class Solution {
 public:
  string minWindow(string s, string t) {
    std::vector<int> need(128, 0);
    for (char c : t) {
      need[c]++;
    }

    int left = 0;
    int right = 0;
    int counter = t.size();
    int start = -1;
    int len = s.size() + 1;
    while (right < s.size()) {
      if (need[s[right]] > 0) {
        counter--;
      }
      need[s[right]]--;
      right++;

      while (counter == 0) {
        if (right - left < len) {
          start = left;
          len = right - left;
        }

        need[s[left]]++;
        if (need[s[left]] > 0) {
          counter++;
        }
        left++;
      }
    }
    return (start == -1 ? "" : s.substr(start, len));
  }
};
