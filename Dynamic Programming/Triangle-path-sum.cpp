//* https://www.geeksforgeeks.org/problems/triangle-path-sum/1

class Solution
{
private:
    int solve(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &tab, int n)
    {
        for (int j = 0; j < n; j++)
        {
            tab[n - 1][j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + tab[i + 1][j];
                int diag = triangle[i][j] + tab[i + 1][j + 1];

                tab[i][j] = min(down, diag);
            }
        }
        return tab[0][0];
    }

public:
    int minimizeSum(int n, vector<vector<int>> &triangle)
    {
        // Code here
        vector<vector<int>> tab(n, vector<int>(n, 0));
        return solve(0, 0, triangle, tab, n);
    }
};