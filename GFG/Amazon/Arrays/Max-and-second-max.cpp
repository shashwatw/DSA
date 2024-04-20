// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/max-and-second-max

//{ Driver Code Starts
// Initial Template for C++

// CPP code to find largest and
// second largest element in the array

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    /* Function to find largest and second largest element
     *sizeOfArray : number of elements in the array
     * arr = input array
     */
    vector<int> largestAndSecondLargest(int sizeOfArray, int arr[])
    {
        int max = INT_MIN, max2 = -1;
        vector<int> res;
        for (int i = 0; i < sizeOfArray; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }

        res.push_back(max);

        for (int i = 0; i < sizeOfArray; i++)
        {
            if (arr[i] > max2 && max > arr[i])
            {
                max2 = arr[i];
            }
        }

        res.push_back(max2);

        return res;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{

    // Testcase input
    int testcases;
    cin >> testcases;

    // Looping through all testcases
    while (testcases--)
    {
        int sizeOfArray;
        cin >> sizeOfArray;

        int arr[sizeOfArray];

        // Array input
        for (int index = 0; index < sizeOfArray; index++)
        {
            cin >> arr[index];
        }
        Solution obj;
        vector<int> ans = obj.largestAndSecondLargest(sizeOfArray, arr);
        cout << ans[0] << ' ' << ans[1] << endl;
    }

    return 0;
}
// } Driver Code Ends