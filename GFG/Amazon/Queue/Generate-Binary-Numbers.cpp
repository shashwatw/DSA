// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-queue/problem/generate-binary-numbers-1587115620

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
    queue<string> q;
    vector<string> res;

    q.push("1");
    res.push_back("1");

    while (res.size() < N)
    {
        string ans = q.front();
        q.pop();

        string ans1 = ans + "0";
        res.push_back(ans1);
        q.push(ans1);

        if (res.size() < N)
        {
            string ans2 = ans + "1";
            res.push_back(ans2);
            q.push(ans2);
        }
    }

    return res;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> ans = generate(n);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends