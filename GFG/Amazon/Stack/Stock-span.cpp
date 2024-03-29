// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-stacks/problem/stock-span-problem-1587115621

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
        stack<int> s;
        vector<int> v;
        s.push(0);
        v.push_back(1);
        int span;

        for (int i = 1; i < n; i++)
        {
            while (!s.empty() && price[s.top()] <= price[i])
            {
                s.pop();
            }

            span = s.empty() ? i + 1 : i - s.top();
            v.push_back(span);
            s.push(i);
        }
        return v;
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
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        vector<int> s = obj.calculateSpan(a, n);

        for (i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends