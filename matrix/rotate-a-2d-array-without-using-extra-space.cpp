// https://www.geeksforgeeks.org/problems/rotate-a-2d-array-without-using-extra-space1004/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    void rotateMatrix(vector<vector<int>> &arr, int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(arr[i][j], arr[j][i]);
            }
        }

        for (int i = 0; i < n / 2; i++)
        {
            swap(arr[i], arr[n - i - 1]);
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++)
        {
            vector<int> a;
            for (int j = 0; j < n; j++)
            {
                cin >> x;
                a.push_back(x);
            }
            arr.push_back(a);
        }
        Solution ob;
        ob.rotateMatrix(arr, n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends