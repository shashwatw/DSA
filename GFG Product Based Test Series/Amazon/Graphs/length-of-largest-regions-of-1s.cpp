//* https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-graphs/problem/length-of-largest-region-of-1s-1587115620

class Solution
{
public:
    // Function to find unit area of the largest region of 1s.

    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, int &cnt)
    {
        vis[row][col] = 1;
        cnt++;
        int n = grid.size();
        int m = grid[0].size();

        int delRow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int delCol[] = {0, 1, 1, 1, 0, -1, -1, -1};

        for (int i = 0; i < 8; i++)
        {
            int fx = row + delRow[i];
            int fy = col + delCol[i];

            if (fx >= 0 && fx < n && fy >= 0 && fy < m && grid[fx][fy] == 1 && !vis[fx][fy])
            {
                dfs(fx, fy, grid, vis, cnt);
            }
        }
    }

    int findMaxArea(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    int cnt = 0; // Start with count 1 for the current cell
                    dfs(i, j, grid, vis, cnt);
                    res = max(res, cnt);
                }
            }
        }
        return res;
    }
};