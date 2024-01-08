// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/minimum-distance-between-two-numbers

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int minDist(int a[], int n, int x, int y)
    {
        int res = INT_MAX;
        int i = -1;
        int j = -1;

        for (int k = 0; k < n; k++)
        {
            if (a[k] == x)
            {
                i = k;
                if (j != -1)
                {
                    res = min(res, abs(i - j));
                }
            }
            else if (a[k] == y)
            {
                j = k;
                if (i != -1)
                {
                    res = min(res, abs(i - j));
                }
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends