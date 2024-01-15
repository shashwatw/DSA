// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/kadanes-algorithm-1587115620
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr: input array
    // n: size of array
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n)
    {
        long long maxEnd = 0;
        long long maxSoFar = LLONG_MIN; // LLONG_MIN is the constant for the minimum value of long long

        for (int i = 0; i < n; i++)
        {
            maxEnd = max(static_cast<long long>(arr[i]), maxEnd + arr[i]);
            maxSoFar = max(maxSoFar, maxEnd);
        }

        return maxSoFar;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, n;

    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {

        cin >> n; // input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; // inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends