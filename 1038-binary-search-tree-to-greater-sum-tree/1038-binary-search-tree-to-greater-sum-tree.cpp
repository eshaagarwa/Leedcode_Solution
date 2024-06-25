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
  TreeNode* bstToGst(TreeNode* root) {
    int prefix = 0;

    function<void(TreeNode*)> reversedInorder = [&](TreeNode* root) {
      if (root == nullptr)
        return;

      reversedInorder(root->right);

      root->val += prefix;
      prefix = root->val;

      reversedInorder(root->left);
    };

    reversedInorder(root);
    return root;
  }
};