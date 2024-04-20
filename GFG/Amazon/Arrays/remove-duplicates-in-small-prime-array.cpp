// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/remove-duplicates-in-small-prime-array

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> removeDuplicate(vector<int> &arr, int n)
    {
        unordered_set<int> seen;
        int i = 0;
        int j = 0;

        while (j < n)
        {
            if (seen.find(arr[j]) == seen.end())
            {
                arr[i++] = arr[j];
                seen.insert(arr[j]);
            }
            j++;
        }

        arr.resize(i);

        return arr;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        vector<int> result = obj.removeDuplicate(A, N);
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
        cout << endl;
    }
}

// } Driver Code Ends