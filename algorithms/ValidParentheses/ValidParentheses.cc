// Source : https://leetcode.com/problems/valid-parentheses
// Author : xjliang
// Date   : 2021-02-11

/***************************************************************************************************** 
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the 
 * input string is valid.
 * 
 * An input string is valid if:
 * 
 * 	Open brackets must be closed by the same type of brackets.
 * 	Open brackets must be closed in the correct order.
 * 
 * Example 1:
 * 
 * Input: s = "()"
 * Output: true
 * 
 * Example 2:
 * 
 * Input: s = "()[]{}"
 * Output: true
 * 
 * Example 3:
 * 
 * Input: s = "(]"
 * Output: false
 * 
 * Example 4:
 * 
 * Input: s = "([)]"
 * Output: false
 * 
 * Example 5:
 * 
 * Input: s = "{[]}"
 * Output: true
 * 
 * Constraints:
 * 
 * 	1 <= s.length <= 104
 * 	s consists of parentheses only '()[]{}'.
 ******************************************************************************************************/

class Solution {
public:
  bool isValid(string s) {
    std::unordered_map<char, char> dict{
      {')', '('},
      {'}', '{'},
      {']', '['}
    };
    std::stack<char> stk;
    for (char c : s) {
      if (dict.find(c) != dict.end()) {
        if (!stk.empty() && dict[c] == stk.top()) {
          stk.pop();
        } else {
          return false;
        }
      } else {
        stk.push(c);
      }
    }
    return stk.empty();
  }
};
