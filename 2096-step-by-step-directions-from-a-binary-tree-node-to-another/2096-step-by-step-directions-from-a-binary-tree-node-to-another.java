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
    // We use StringBuilder instead of String because String is immutable,
    // so appending a character takes O(length of string).
    // ans is a String[1] instead of String because in Java, arrays are passed by reference.
    void getPath(TreeNode cur, int targetValue, StringBuilder path, String[] ans) {
        if (cur == null)
            return;
        if (cur.val == targetValue)
            ans[0] = path.toString();
        int strLen = path.length();
        path.append("L");
        getPath(cur.left, targetValue, path, ans);
        path.replace(strLen, strLen+1, "R");
        getPath(cur.right, targetValue, path, ans);
        path.delete(strLen, strLen+1);
    }
    public String getDirections(TreeNode root, int startValue, int destValue) {
        StringBuilder tmpPath = new StringBuilder();
        String[] startPath = {""}, destPath = {" "};
        // Find the first point at which the paths diverge
        getPath(root, startValue, tmpPath, startPath);
        getPath(root, destValue, tmpPath, destPath);
        int i = 0;
        while (i < Math.min(startPath[0].length(), destPath[0].length()) && startPath[0].charAt(i) == destPath[0].charAt(i))
            i++;
        return "U".repeat(startPath[0].length()-i) + destPath[0].substring(i);
    }
}