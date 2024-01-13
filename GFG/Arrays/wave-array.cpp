// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/wave-array-1587115621
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// #include <algorithm>

// } Driver Code Ends
class Solution
{
public:
    // arr: input array
    // n: size of array
    // Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int> &arr)
    {
        if (n % 2 != 0)
        {
            for (int i = 0; i < n - 1; i += 2)
            {
                swap(arr[i], arr[i + 1]);
            }
        }
        else
        {
            for (int i = 0; i < n; i += 2)
            {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t, n;
    cin >> t;   // Input testcases
    while (t--) // While testcases exist
    {
        cin >> n;         // input size of array
        vector<int> a(n); // declare vector of size n
        for (int i = 0; i < n; i++)
            cin >> a[i]; // input elements of array
        sort(a.begin(), a.end());
        Solution ob;
        ob.convertToWave(n, a);

        for (int i = 0; i < n; i++)
            cout << a[i] << " "; // print array

        cout << endl;
    }
}
// } Driver Code Ends