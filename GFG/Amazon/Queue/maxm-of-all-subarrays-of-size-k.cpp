// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-queue/problem/maximum-of-all-subarrays-of-size-k3101

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find maximum of each subarray of size k.

    vector<int> max_of_subarrays(int *arr, int n, int K)
    {
        deque<int> Qi(K);
        vector<int> res;

        // Process first window
        int i;
        for (i = 0; i < K; ++i)
        {
            // Remove elements smaller than or equal to arr[i] from the end
            while (!Qi.empty() && arr[i] >= arr[Qi.back()])
                Qi.pop_back();

            // Add current index to the deque
            Qi.push_back(i);
        }

        // Process rest of the elements
        for (; i < n; ++i)
        {
            // The element at the front of the deque is the maximum element of the previous window
            res.push_back(arr[Qi.front()]);

            // Remove elements which are out of the current window
            while (!Qi.empty() && Qi.front() <= i - K)
                Qi.pop_front();

            // Remove elements smaller than or equal to arr[i] from the end
            while (!Qi.empty() && arr[i] >= arr[Qi.back()])
                Qi.pop_back();

            // Add current index to the deque
            Qi.push_back(i);
        }

        // Push maximum element of last window to result
        res.push_back(arr[Qi.front()]);

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

        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends