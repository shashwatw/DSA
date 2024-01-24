// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-strings/problem/check-if-string-is-rotated-by-two-places-1587115620

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to check if a string can be obtained by rotating
    // another string by exactly 2 places.
    bool isRotated(string a, string b)
    {
        int n = a.size();

        if (n == 1)
        {
            return false;
        }

        string clockwiseRotation = a.substr(n - 2) + a.substr(0, n - 2);
        if (clockwiseRotation == b)
        {
            return true;
        }

        string anticlockwiseRotation = a.substr(2) + a.substr(0, 2);
        if (anticlockwiseRotation == b)
        {
            return true;
        }

        return false;
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
        string b;
        cin >> s >> b;
        Solution obj;
        cout << obj.isRotated(s, b) << endl;
    }
    return 0;
}

// } Driver Code Ends