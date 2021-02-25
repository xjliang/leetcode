// Source : https://leetcode.com/problems/binary-tree-level-order-traversal
// Author : xjliang
// Date   : 2021-02-25

/*****************************************************************************************************
 *
 * Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from
 * left to right, level by level).
 *
 * Example 1:
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[9,20],[15,7]]
 *
 * Example 2:
 *
 * Input: root = [1]
 * Output: [[1]]
 *
 * Example 3:
 *
 * Input: root = []
 * Output: []
 *
 * Constraints:
 *
 * 	The number of nodes in the tree is in the range [0, 2000].
 * 	-1000 <= Node.val <= 1000
 ******************************************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> result;
    std::queue<const TreeNode*> que;
    if (root) {
      que.push(root);
    }
    int level = 0;
    while (!que.empty()) {
      result.push_back(std::vector<int>());
      int sz = que.size();
      while (sz-- > 0) {
        auto node = que.front();
        que.pop();

        result[level].push_back(node->val);
        if (node->left) {
          que.push(node->left);
        }
        if (node->right) {
          que.push(node->right);
        }
      }
      level++;
    }

    return result;
  }
};
