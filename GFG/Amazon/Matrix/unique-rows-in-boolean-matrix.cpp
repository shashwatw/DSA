// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-matrix/problem/unique-rows-in-boolean-matrix

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col);

// } Driver Code Ends
class Solution
{
public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col)
    {
        unordered_set<string> s;
        vector<vector<int>> res;

        for (int i = 0; i < row; i++)
        {
            string str = "";
            for (int j = 0; j < col; j++)
            {
                str += to_string(M[i][j]);
            }

            if (s.find(str) == s.end())
            { // Check if the row is not already in the set
                s.insert(str);
                vector<int> uniqueRow;

                for (int j = 0; j < col; j++)
                {
                    uniqueRow.push_back(M[i][j]); // Store the elements of the unique row
                }
                res.push_back(uniqueRow); // Push the unique row into the result vector
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        int a[MAX][MAX];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        Solution ob;
        vector<vector<int>> vec = ob.uniqueRow(a, n, m);
        for (int i = 0; i < vec.size(); i++)
        {
            for (int x : vec[i])
            {
                cout << x << " ";
            }
            cout << "$";
        }
        cout << endl;
    }
}

// } Driver Code Ends