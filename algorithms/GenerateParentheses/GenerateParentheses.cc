// Source : https://leetcode.com/problems/generate-parentheses/
// Author : xjliang
// Date   : 2021-02-10

/***************************************************************************************************** 
 *
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed 
 * parentheses.
 * 
 * Example 1:
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 * Example 2:
 * Input: n = 1
 * Output: ["()"]
 * 
 * Constraints:
 * 
 * 	1 <= n <= 8
 ******************************************************************************************************/

class Solution {
  const char kOpen = '(';
  const char kClose = ')';
 public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> result;
    std::string track;
    backtrack(result, track, n, 0, 0);
    return result;
  }
  
  void backtrack(std::vector<std::string>& result, std::string& track,
                 int n, int open, int close) {
    if (open > n) {
      return ;
    }
    if (close == n) {
      result.push_back(track);
      return ;
    }
    
    track.push_back(kOpen);
    backtrack(result, track, n, open + 1, close);
    track.pop_back();
    
    if (open > close) {
      track.push_back(kClose);
      backtrack(result, track, n, open, close + 1);
      track.pop_back();
    }
  }
};
