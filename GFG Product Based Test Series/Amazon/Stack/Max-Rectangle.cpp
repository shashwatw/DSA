// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-stacks/problem/max-rectangle

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
public:
    int maxArea(int M[MAX][MAX], int n, int m)
    {
        int result = maxHist(M[0], m);

        // Iterate over rows to find the maximum rectangular area
        // considering each row as a histogram
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // If M[i][j] is 1, then add M[i - 1][j]
                if (M[i][j])
                {
                    M[i][j] += M[i - 1][j];
                }
            }

            // Update result if the area with the current row (as the last
            // row) of the rectangle is more
            result = max(result, maxHist(M[i], m));
        }

        return result;
    }

    int maxHist(int row[], int C)
    {
        stack<int> result;
        int top_val;      // Top of the stack
        int max_area = 0; // Initialize max area in the current row (or histogram)
        int area = 0;     // Initialize area with the current top

        // Run through all bars of the given histogram (or row)
        int i = 0;
        while (i < C)
        {
            // If this bar is higher than the bar on top of the stack,
            // push it to the stack
            if (result.empty() || row[result.top()] <= row[i])
            {
                result.push(i++);
            }
            else
            {
                // If this bar is lower than the top of the stack, then
                // calculate the area of the rectangle with the stack top as
                // the smallest (or minimum height) bar. 'i' is the 'right index'
                // for the top, and the element before the top in the stack is the 'left index'
                top_val = row[result.top()];
                result.pop();
                area = top_val * i;

                if (!result.empty())
                {
                    area = top_val * (i - result.top() - 1);
                }
                max_area = max(area, max_area);
            }
        }

        // Now pop the remaining bars from the stack and calculate
        // the area with every popped bar as the smallest bar
        while (!result.empty())
        {
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;

            if (!result.empty())
            {
                area = top_val * (i - result.top() - 1);
            }
            max_area = max(area, max_area);
        }
        return max_area;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends