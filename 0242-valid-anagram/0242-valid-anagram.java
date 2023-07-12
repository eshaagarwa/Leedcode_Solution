public class Solution {
    public boolean isAnagram(String s, String t) {
        int[] freq  = new int[26];

        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
         freq[ch-'a'] = freq[ch-'a']+1;
        
    }
        
        for(int i=0;i<t.length();i++){
            char ch = t.charAt(i);
         freq[ch-'a'] = freq[ch-'a']-1;
        
    }
    for(int i=0;i<freq.length;i++){
        if(freq[i]!=0){
            return false;
        }
    }
    return true;
    }
}