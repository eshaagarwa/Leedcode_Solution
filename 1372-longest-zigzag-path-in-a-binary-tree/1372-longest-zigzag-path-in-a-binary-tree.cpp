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
struct T {
  int leftMax;
  int rightMax;
  int subtreeMax;
};

class Solution {
 public:
  int longestZigZag(TreeNode* root) {
    return dfs(root).subtreeMax;
  }

 private:
  T dfs(TreeNode* root) {
    if (root == nullptr)
      return {-1, -1, -1};
    const T left = dfs(root->left);
    const T right = dfs(root->right);
    const int leftZigZag = left.rightMax + 1;
    const int rightZigZag = right.leftMax + 1;
    const int subtreeMax =
        max({leftZigZag, rightZigZag, left.subtreeMax, right.subtreeMax});
    return {leftZigZag, rightZigZag, subtreeMax};
  }
};