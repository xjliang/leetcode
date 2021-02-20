// Source : https://leetcode.com/problems/word-search
// Author : xjliang
// Date   : 2021-02-20

/*****************************************************************************************************
 *
 * Given an m x n board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cells, where "adjacent" cells are
 * horizontally or vertically neighboring. The same letter cell may not be used more than once.
 *
 * Example 1:
 *
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
 * Output: true
 *
 * Example 2:
 *
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
 * Output: true
 *
 * Example 3:
 *
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
 * Output: false
 *
 * Constraints:
 *
 * 	m == board.length
 * 	n = board[i].length
 * 	1 <= m, n <= 200
 * 	1 <= word.length <= 103
 * 	board and word consists only of lowercase and uppercase English letters.
 ******************************************************************************************************/

class Solution {
 public:
  bool exist(std::vector<std::vector<char>>& board, string word) {
    if (board.empty() || board[0].empty()) {
      return false;
    }

    const int m = board.size();
    const int n = board[0].size();
    std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (dfs(board, m, n, i, j, word, 0, visited)) {
          return true;
        }
      }
    }
    return false;
  }

  bool dfs(const std::vector<std::vector<char>>& board, int m, int n,
           int i, int j, const std::string& word, int curr,
           std::vector<std::vector<bool>>& visited) {
    if (curr == word.size()) {
      return true;
    }
    if (i >= m || i < 0 || j >= n || j < 0 ||
        visited[i][j] || board[i][j] != word[curr]) {
      return false;
    }
    visited[i][j] = true;

    const static int offset[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
    for (int k = 0; k < 4; k++) {
      if (dfs(board, m, n, i + offset[k][0], j + offset[k][1],
              word, curr + 1, visited)) {
        return true;
      }
    }

    visited[i][j] = false;
    return false;
  }
};
