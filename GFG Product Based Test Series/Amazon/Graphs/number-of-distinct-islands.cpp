//* https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-graphs/problem/find-the-number-of-islands

class Solution
{
private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // traverse in the neighbours and mark them if its a length
            for (int delrow = -1; delrow <= 1; delrow++)
            {
                for (int delcol = -1; delcol <= 1; delcol++)
                {
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    if (nrow >= 0 && nrow < n & ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
                    {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }

public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (!vis[row][col] && grid[row][col] == '1')
                {
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
};