// https://www.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int kthLargest(vector<int> &arr, int N, int K)
    {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq; // minheap

        for (int i = 0; i < N; i++)
        {
            int sum = 0;
            for (int j = i; j < N; j++)
            {
                sum += arr[j];

                if (pq.size() < K)
                {
                    pq.push(sum);
                }
                else
                {
                    if (pq.top() < sum)
                    {
                        pq.pop();
                        pq.push(sum);
                    }
                }
            }
        }
        return pq.top();
    }
};

//{ Driver Code Starts.

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N;
        cin >> K;
        vector<int> Arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> Arr[i];
        }
        Solution ob;
        int ans = ob.kthLargest(Arr, N, K);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends