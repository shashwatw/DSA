// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/trapping-rain-water-1587115621

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{

    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {
        int l = 0;
        int r = n - 1;
        int leftMax = 0;
        int rightMax = 0;
        long long res = 0;

        while (l <= r)
        {
            if (arr[l] <= arr[r])
            {
                // Process left side
                if (arr[l] >= leftMax)
                {
                    leftMax = arr[l];
                }
                else
                {
                    res += leftMax - arr[l];
                }
                l++;
            }
            else
            {
                // Process right side
                if (arr[r] >= rightMax)
                {
                    rightMax = arr[r];
                }
                else
                {
                    res += rightMax - arr[r];
                }
                r--;
            }
        }

        return res;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;

        int a[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        // calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
}
// } Driver Code Ends