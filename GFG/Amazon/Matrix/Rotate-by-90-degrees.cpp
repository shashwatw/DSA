// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-matrix/problem/rotate-by-90-degree0356

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>> &matrix);

// } Driver Code Ends
// User function template for C++

/* matrix : given input matrix, you are require
 to change it in place without using extra space */
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int row = 0; row < n - 1; row++)
    {
        for (int col = row + 1; col < n; col++)
        {
            swap(matrix[row][col], matrix[col][row]);
        }
    }

    for (int col = 0; col < n / 2; col++)
    {
        swap(matrix[col], matrix[n - col - 1]);
    }
}

// 1 2 3
// 4 5 6
// 7 8 9

// Transpose
//  1 4 7
//  2 5 8
//  3 6 9

// Final
// 3 6 9
// 2 5 8
// 1 4 7

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n);
        for (int i = 0; i < n; i++)
        {
            matrix[i].resize(n);
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}

// } Driver Code Ends