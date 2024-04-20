// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-heap/problem/nearly-sorted-1587115620

// Intuition: Each a[element is at max K posn away from its sorted posn that's why a min heap of K size can determine smallest element in sorted order

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return the sorted array.
    vector<int> nearlySorted(int arr[], int num, int K)
    {
        // Your code here
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> ans;

        for (int i = 0; i < num; i++)
        {
            while (pq.size() > K)
            {
                ans.push_back(pq.top());
                pq.pop();
            }
            pq.push(arr[i]);
        }

        while (!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int num, K;
        cin >> num >> K;

        int arr[num];
        for (int i = 0; i < num; ++i)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res = ob.nearlySorted(arr, num, K);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";

        cout << endl;
    }

    return 0;
}

// } Driver Code Ends