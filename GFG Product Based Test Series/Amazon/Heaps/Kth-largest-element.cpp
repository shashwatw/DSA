// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-heap/problem/k-largest-elements3736

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;

        vector<int> ans;

        for (int i = 0; i < k; i++)
        {
            pq.push(arr[i]);
        }

        for (int i = k; i < n; i++)
        {
            if (pq.top() < arr[i])
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }

        while (!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> result = ob.kLargest(arr, n, k);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends