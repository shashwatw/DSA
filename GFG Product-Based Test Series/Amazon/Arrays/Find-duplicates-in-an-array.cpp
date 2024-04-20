// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/find-duplicates-in-an-array

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> duplicates(long long arr[], int n)
    {
        // code here
        int D = n + 1;

        for (int i = 0; i < n; i++)
        {
            arr[arr[i] % D] += D;
        }

        vector<int> res;
        // for(int i=0; i<n; i++)
        //     cout<< (arr[i]%D);

        for (int i = 0; i < n; i++)
        {
            if (arr[i] / D >= 2)
                res.push_back(i);
        }

        if (res.size() == 0)
            res.push_back(-1);
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends