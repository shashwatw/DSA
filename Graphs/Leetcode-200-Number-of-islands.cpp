// https://leetcode.com/problems/number-of-islands/description/

class Solution
{
public:
    void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis)
    {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        q.push({row, col});
        while (!q.empty())
        {
            int rows = q.front().first;
            int cols = q.front().second;
            q.pop();
            // traverse all the neighbours
            for (int delrow = -1; delrow <= 1; delrow++)
            {
                for (int delcol = -1; delcol <= 1; delcol++)
                {
                    int nr = rows + delrow;
                    int nc = cols + delcol;
                    // traverse sides ones
                    if (delrow != 0 && delcol != 0)
                    {
                        continue;
                    }
                    //  check for any invalid conditions
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == '1')
                    {
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        vector<vector<char>> ans;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int c = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    bfs(i, j, grid, vis);
                    c++;
                }
            }
        }
        return c;
    }
};