// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/rearrange-an-array-with-o1-extra-space3142
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // arr: input array
    // n: size of array
    // Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    // with O(1) extra space.
    void arrange(long long arr[], int n)
    {
        int D = n;
        long long newer;
        for (int i = 0; i < n; i++)
        {
            newer = arr[arr[i] % D] % D;
            arr[i] = D * newer + arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            arr[i] /= D;
        }
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
        long long A[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        Solution ob;
        // calling arrange() function
        ob.arrange(A, n);

        // printing the elements
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends