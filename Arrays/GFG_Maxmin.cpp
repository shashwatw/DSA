// https://practice.geeksforgeeks.org/problems/max-min/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#include <stdlib.h>
class Solution
{
    //   private:
    //   void print(int A[], int N)
    //   {
    //         for(int i = 0 ; i < N; i++)
    //         {
    //             cout << A[i] <<" ";
    //         }
    //   }

public:
    int findSum(int A[], int N)
    {
        sort(A, A + N);
        // 	print(A, N);

        int min = A[0];
        int max = A[N - 1];

        return max + min;
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
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        int ans = ob.findSum(arr, n);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends