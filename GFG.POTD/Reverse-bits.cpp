// https://www.geeksforgeeks.org/problems/reverse-bits3556/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long reversedBits(long long x)
    {
        // code here
        string ans;
        for (int i = 31; i >= 0; i--)
        {
            int k = x >> i;

            if (k & 1)
            {
                ans += '1';
            }
            else
            {
                ans += '0';
            }
        }

        reverse(ans.begin(), ans.end());

        long long dec_num = 0;

        for (int i = 0; i < 32; i++)
        {
            if (ans[i] == '1')
                dec_num += pow(2, 32 - i - 1);
        }

        return dec_num;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long X;

        cin >> X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends