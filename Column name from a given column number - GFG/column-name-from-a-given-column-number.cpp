//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    string colName (long long int n)
    {
        --n;
        
        string ans = "";
        while(n > -1){
            int cur = n % 26;
            
            ans += (char)(cur + 'A');
            
            n /= 26;
            --n;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends