// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/max-circular-subarray-sum-1587115620

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr: input array
    // num: size of array
    // Function to find maximum circular subarray sum.
    int kadane(int arr[], int n)
    {
        int maxEnd = 0;
        int maxSoFar = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            maxEnd = max(arr[i], maxEnd + arr[i]);
            maxSoFar = max(maxSoFar, maxEnd);
        }

        return maxSoFar;
    }

    int circularSubarraySum(int arr[], int num)
    {
        int maxNonCircular = kadane(arr, num);

        // Calculate total sum and negate each element in the array
        int totalSum = 0;
        for (int i = 0; i < num; i++)
        {
            totalSum += arr[i];
            arr[i] = -arr[i];
        }

        // Maximum circular subarray sum is the total sum minus the minimum non-circular subarray sum
        int maxCircular = totalSum + kadane(arr, num);

        // If all elements are negative, return the maximum non-circular subarray sum
        if (maxCircular == 0)
        {
            return maxNonCircular;
        }

        return max(maxNonCircular, maxCircular);
    }
};

//{ Driver Code Starts.

int main()
{
    int T;

    // testcases
    cin >> T;

    while (T--)
    {
        int num;

        // size of array
        cin >> num;
        int arr[num];

        // inserting elements
        for (int i = 0; i < num; i++)
            cin >> arr[i];

        Solution ob;
        // calling function
        cout << ob.circularSubarraySum(arr, num) << endl;
    }

    return 0;
}
// } Driver Code Ends