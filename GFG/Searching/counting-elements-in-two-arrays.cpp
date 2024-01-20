// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-searching/problem/counting-elements-in-two-arrays

//{ Driver Code Starts
// C++ implementation of For each element in 1st
// array count elements less than or equal to it
// in 2nd array
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
class Solution
{
public:
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], int m, int n)
    {
        vector<int> res;
        unordered_map<int, int> map;

        // TC = O(m+n)

        int maxVal = INT_MIN;
        for (int i = 0; i < m; i++)
        {
            maxVal = max(maxVal, arr1[i]);
        }

        for (int i = 0; i < n; i++)
        {
            map[arr2[i]]++;
            maxVal = max(arr2[i], maxVal);
        }

        vector<int> count(maxVal + 1, 0);
        for (const auto &entry : map)
        {
            count[entry.first] = entry.second;
        }

        for (int i = 1; i <= maxVal; i++)
        {
            count[i] += count[i - 1];
        }

        for (int i = 0; i < m; i++)
        {
            res.push_back(count[arr1[i]]);
        }

        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        int arr1[m], arr2[n];
        for (int i = 0; i < m; i++)
            cin >> arr1[i];
        for (int j = 0; j < n; j++)
            cin >> arr2[j];
        Solution obj;
        vector<int> res = obj.countEleLessThanOrEqual(arr1, arr2, m, n);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends