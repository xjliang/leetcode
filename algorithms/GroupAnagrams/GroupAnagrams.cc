// Source : https://leetcode.com/problems/group-anagrams/
// Author : xjliang
// Date   : 2021-02-15

/***************************************************************************************************** 
 *
 * Given an array of strings strs, group the anagrams together. You can return the answer in any order.
 * 
 * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
 * typically using all the original letters exactly once.
 * 
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 * 
 * Constraints:
 * 
 * 	1 <= strs.length <= 104
 * 	0 <= strs[i].length <= 100
 * 	strs[i] consists of lower-case English letters.
 ******************************************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution1 {
 public:
	 std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> dict;
    for (const auto& str : strs) {
      std::string temp(str);
      std::sort(temp.begin(), temp.end());      
      dict[temp].push_back(str);
    }
    
		std::vector<std::vector<std::string>> result;
    for (auto& item : dict) {
      result.push_back(item.second);
    }
		std::cout << dict["aet"].size() << std::endl;
    return result;
  }
};

class Solution2 {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> dict;
    for (const auto& str : strs) {
      std::string temp(str);
      std::sort(temp.begin(), temp.end());
      dict[temp].push_back(str);
    }

    vector<vector<string>> result;
    for (auto&& item : dict) {
      result.push_back(std::move(item.second));
    }
		std::cout << dict["aet"].size() << std::endl;
    return result;
  }
};

int main(int argc, char *argv[]) {
	std::vector<std::string> strs{"eat", "tea", "tan", "ate"};
	Solution1().groupAnagrams(strs);
	Solution2().groupAnagrams(strs);

	return 0;
}
