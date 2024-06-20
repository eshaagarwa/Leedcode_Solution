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
  int maxLevelSum(TreeNode* root) {
    int ans = 0;
    int maxLevelSum = INT_MIN;
    queue<TreeNode*> q{{root}};

    for (int level = 1; !q.empty(); ++level) {
      int levelSum = 0;
      for (int sz = q.size(); sz > 0; --sz) {
        TreeNode* node = q.front();
        q.pop();
        levelSum += node->val;
        if (node->left != nullptr)
          q.push(node->left);
        if (node->right != nullptr)
          q.push(node->right);
      }
      if (levelSum > maxLevelSum) {
        maxLevelSum = levelSum;
        ans = level;
      }
    }

    return ans;
  }
};