// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-sorting/problem/product-array-puzzle4634
//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

// points : 2-d vector containing the (x, y) points
// K : number of closest points that we need to find
// return 2d vector containing the k points in increasing order of distance from origin

class Solution
{
public:
    static bool comparePoints(const vector<int> &a, const vector<int> &b)
    {
        int distanceA = a[0] * a[0] + a[1] * a[1];
        int distanceB = b[0] * b[0] + b[1] * b[1];

        return distanceA < distanceB || (distanceA == distanceB && a < b);
    }

    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        // Sort points using the custom comparator function
        sort(points.begin(), points.end(), comparePoints);

        // Return the first K closest points
        return vector<vector<int>>(points.begin(), points.begin() + K);
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

        vector<vector<int>> p, res;

        for (int i = 0; i < n; ++i)
        {
            vector<int> vec(2);
            cin >> vec[0] >> vec[1];
            p.push_back(vec);
        }
        Solution obj;
        res = obj.kClosest(p, k);

        for (int i = 0; i < k; ++i)
        {
            cout << res[i][0] << " " << res[i][1] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends