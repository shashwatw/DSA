// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/third-largest-element

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int thirdLargest(int a[], int n)
    {
        int max = a[0];
        int curMax = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > max)
            {
                max = a[i];
            }
        }

        for (int j = 0; j < 2; j++)
        {
            curMax = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] > curMax && max > a[i])
                {
                    curMax = a[i];
                }
            }
            max = curMax;
        }

        return curMax;
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
        Solution obj;
        cout << obj.thirdLargest(a, n) << endl;
    }
}
// } Driver Code Ends