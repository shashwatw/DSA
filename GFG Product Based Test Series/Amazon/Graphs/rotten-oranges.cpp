//* https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-graphs/problem/rotten-oranges2536

class Solution
{
public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {
        // Code here
        int m = grid.size();
        int n = grid[0].size();

        int vis[m][n];

        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});
                }
                else
                {
                    vis[i][j] = 0;
                }
            }
        }

        int tme = 0;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;

            tme = max(tme, t);

            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 & ncol < n && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2)
                {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (vis[i][j] != 2 && grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return tme;
    }
};