// Source : https://leetcode.com/problems/binary-tree-inorder-traversal
// Author : xjliang
// Date   : 2021-02-22

/*****************************************************************************************************
 *
 * Given the root of a binary tree, return the inorder traversal of its nodes' values.
 *
 * Example 1:
 *
 * Input: root = [1,null,2,3]
 * Output: [1,3,2]
 *
 * Example 2:
 *
 * Input: root = []
 * Output: []
 *
 * Example 3:
 *
 * Input: root = [1]
 * Output: [1]
 *
 * Example 4:
 *
 * Input: root = [1,2]
 * Output: [2,1]
 *
 * Example 5:
 *
 * Input: root = [1,null,2]
 * Output: [1,2]
 *
 * Constraints:
 *
 * 	The number of nodes in the tree is in the range [0, 100].
 * 	-100 <= Node.val <= 100
 *
 * Follow up:
 *
 * Recursive solution is trivial, could you do it iteratively?
 *
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

// recursively
class Solution1 {
 public:
  std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> result;
    inorderTraversalHelper(result, root);
    return result;
  }

  void inorderTraversalHelper(std::vector<int>& result, TreeNode* node) {
    if (node == nullptr) {
      return ;
    }

    inorderTraversalHelper(result, node->left);
    result.push_back(node->val);
    inorderTraversalHelper(result, node->right);
  }
};

// iteratively
class Solution2 {
 public:
   std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> result;
    std::stack<TreeNode*> stk;
    while (root || !stk.empty()) {
      while (root) {
        stk.push(root);
        root = root->left;
      }

      root = stk.top();
      stk.pop();
      result.push_back(root->val);

      root = root->right;
    }
    return result;
  }
};
