/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    static int count=0;
    public int goodNodes(TreeNode root) {
        count = 0;
        int maxValue = root.val;
        checkGoodNodes(root,maxValue);

        return count;    
    }

    private void checkGoodNodes(TreeNode root, int maxValue){
        if(root==null){
            return;
        }
        if(maxValue<=root.val){
            maxValue=root.val;
            count++;
            System.out.println("count: "+count+" maxValue: "+maxValue);
        }

        checkGoodNodes(root.left,maxValue);
        checkGoodNodes(root.right,maxValue);

    }
}