// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/container-with-most-water0535

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
// User function template for C++

long long maxArea(long long A[], int len)
{
    int left = 0;
    int right = len - 1;
    long long maxArea = 0;

    while (left < right)
    {
        int width = right - left;
        long long height = min(A[left], A[right]);

        maxArea = max(maxArea, width * height);

        if (A[left] < A[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return maxArea;
}

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << maxArea(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends