class Solution {
    public int findComplement(int num) {
        if(num==0)return 1;
        int bitlength = (int)(Math.log(num)/ Math.log(2)) + 1;
	    int bitmask = (1 << bitlength) - 1;
	    return bitmask^num;
          
    }
}