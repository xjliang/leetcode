// Source : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
// Author : xjliang
// Date   : 2021-02-26

/*****************************************************************************************************
 *
 * Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary
 * tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
 *
 * Example 1:
 *
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 *
 * Example 2:
 *
 * Input: preorder = [-1], inorder = [-1]
 * Output: [-1]
 *
 * Constraints:
 *
 * 	1 <= preorder.length <= 3000
 * 	inorder.length == preorder.length
 * 	-3000 <= preorder[i], inorder[i] <= 3000
 * 	preorder and inorder consist of unique values.
 * 	Each value of inorder also appears in preorder.
 * 	preorder is guaranteed to be the preorder traversal of the tree.
 * 	inorder is guaranteed to be the inorder traversal of the tree.
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
  TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
    std::map<int, int> in_map;
    for (int i = 0; i < inorder.size(); i++) {
      in_map[inorder[i]] = i;
    }

    return buildTreeRec(preorder, 0, preorder.size() - 1, in_map, 0, preorder.size() - 1);
  }

  TreeNode* buildTreeRec(const vector<int>& preorder, int pre_beg, int pre_end,
                       std::map<int, int>& in_map, int in_beg, int in_end) {
    if (pre_beg > pre_end) {
      return nullptr;
    }

    int root_val = preorder[pre_beg];
    int root_index = in_map[root_val];
    int left_len = root_index - in_beg;
    TreeNode* root = new TreeNode(root_val);
    root->left = buildTreeRec(preorder, pre_beg + 1, pre_beg + left_len, in_map,
                             in_beg, in_beg + left_len);
    root->right = buildTreeRec(preorder, pre_beg + left_len + 1, pre_end, in_map,
                             in_beg + left_len + 1, in_end);
    return root;
  }

};
