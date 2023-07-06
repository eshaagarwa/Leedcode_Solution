public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int k = matrix[0].length -1;

        // find the row that matrix[r][k] > target && matrix[r-1][k] < target;

        int t = 0;
        int b = matrix.length -1;
        if(target < matrix[0][0] || target > matrix[matrix.length-1][matrix[0].length-1]) return false;
        while(t <= b){
            int mid = t + (b-t)/2;
            if(matrix[mid][k] == target) return true;
            if(matrix[mid][k] > target){
                b = mid-1;
            }else{
                t = mid+1;
            }
        }

        int l = t;

        t = 0;
        b = matrix[0].length -1;
        while(t <= b){
            int mid = t + (b-t)/2;
            if(matrix[l][mid] == target) return true;
            if(matrix[l][mid] > target){
                b = mid -1;
            }else{
                t = mid + 1;
            }
        }

        return false;
    }
}