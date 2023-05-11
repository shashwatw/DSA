// https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++
#include <stdlib.h>
class Solution
{
public:
    // Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)
    {
        set<int> mp;
        for (int i = 0; i < n; i++)
        {
            mp.insert(a[i]);
        }
        for (int j = 0; j < m; j++)
        {
            mp.insert(b[j]);
        }

        int N = mp.size();

        return N;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n, m;
        cin >> n >> m;
        int a[n], b[m];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];
        Solution ob;
        cout << ob.doUnion(a, n, b, m) << endl;
    }

    return 0;
}
// } Driver Code Ends