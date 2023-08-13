//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int xorResult = 0;
    
    // XOR all the numbers in the array
    for (int num : nums) {
        xorResult ^= num;
    }
    
    // Find the rightmost set bit in xorResult
    int rightmostSetBit = xorResult & -xorResult;
    
    int num1 = 0, num2 = 0;
    
    // Partition the array based on the rightmost set bit
    for (int num : nums) {
        if (num & rightmostSetBit) {
            num1 ^= num;
        } else {
            num2 ^= num;
        }
    }
    
    return {min(num1, num2), max(num1, num2)};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends