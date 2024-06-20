class Solution {
public:
// Function to find the maximum number of vowels in a substring of length k
    int maxVowels(string s, int k) {
        // Variable to keep track of the count of vowels in the current substring
        int count = 0;
        // String containing all the vowels
        string vowels = "aeiou";

        // Loop to count vowels in the first substring of length k
        for (int i = 0; i < k; i++) {
            // Check if the current character is a vowel
            if (vowels.find(s[i]) != string::npos)
                count++;
        }

        // Variables for sliding window approach
        int j = 0;      // Start of the current substring
        int maxx = count;  // Variable to store the maximum count of vowels

        // Loop to slide the window through the string and update the count of vowels
        for (int i = k; i < s.length(); i++) {
            // If the character at the start of the current substring is a vowel, decrease the count
            if (vowels.find(s[j]) != string::npos)
                count--;

            // If the character at the end of the current substring is a vowel, increase the count
            if (vowels.find(s[i]) != string::npos)
                count++;

            j++;  // Move the window one position to the right

            // Update the maximum count of vowels encountered so far
            maxx = max(maxx, count);

            // If the maximum count equals k, no need to continue searching, return k
            if (maxx == k)
                return maxx;
        }

        // Return the maximum count of vowels found in any substring
        return maxx;
    }
};