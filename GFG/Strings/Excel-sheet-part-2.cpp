// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-strings/problem/excel-sheet-part-21138

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int ExcelColumnNumber(string s)
    {
        int ans = 0;
        int j = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            ans += pow(26, j) * (int(s[i]) - 64);
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.ExcelColumnNumber(s) << endl;
    }
}
// } Driver Code Ends