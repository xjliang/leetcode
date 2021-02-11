// Source : https://leetcode.com/problems/letter-combinations-of-a-phone-number
// Author : xjliang
// Date   : 2021-02-11

/***************************************************************************************************** 
 *
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that 
 * the number could represent. Return the answer in any order.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does 
 * not map to any letters.
 * 
 * Example 1:
 * 
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * Example 2:
 * 
 * Input: digits = ""
 * Output: []
 * 
 * Example 3:
 * 
 * Input: digits = "2"
 * Output: ["a","b","c"]
 * 
 * Constraints:
 * 
 * 	0 <= digits.length <= 4
 * 	digits[i] is a digit in the range ['2', '9'].
 ******************************************************************************************************/

class Solution {
  const std::vector<std::string> kDict{
      "", // 0
      "", // 1
      "abc", // 2
      "def", // 3
      "ghi", // 4
      "jkl", // 5
      "mno", // 6
      "pqrs", // 7
      "utv", // 8
      "wxyz" // 9
    };
public:
  vector<string> letterCombinations(string digits) {    
    std::vector<std::string> result;
    if (digits.empty()) {
      return result;
    }
    std::string track;
    backtrack(result, track, digits, 0);
    return result;
  }
  
  void backtrack(std::vector<std::string>& result, std::string& track,
                 const std::string& digits, int curr) {
    if (curr == digits.size()) {
      result.push_back(track);
      return ;
    }
    
    int index = digits[curr] - '0';
    const std::string& choices = kDict[index];
    for (char c : choices) {
      track.push_back(c);
      backtrack(result, track, digits, curr + 1);
      track.pop_back();
    }
  }
};
