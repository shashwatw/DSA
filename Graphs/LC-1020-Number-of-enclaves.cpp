//^ https://leetcode.com/problems/number-of-enclaves/

//! Intuition
//* Here we do similar to 01 Matrix logic ques
//* we traverse through all the boundaries of the grid and check for the lands
//* I mark the boundary lands visited and also call their dfs and mark every land connected to boundary land as visited
//* Finally I compare with initial grid and vis matrix and check that if any land of the grid was still not visited then it must be surrounded by water from all sides and hence is unreachable
//* So i count these type of cells and finally return the count

//& APPROACH - BFS

//~ CODE:
class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, int delRow[], int delCol[])
    {
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                dfs(nrow, ncol, vis, grid, delRow, delCol);
            }
        }
    }

    int numEnclaves(vector<vector<int>> &grid)
    {

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++)
        {
            if (!vis[0][j] && grid[0][j] == 1)
            {
                dfs(0, j, vis, grid, delRow, delCol);
            }

            if (!vis[n - 1][j] && grid[n - 1][j] == 1)
            {
                dfs(n - 1, j, vis, grid, delRow, delCol);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!vis[i][0] && grid[i][0] == 1)
            {
                dfs(i, 0, vis, grid, delRow, delCol);
            }

            if (!vis[i][m - 1] && grid[i][m - 1] == 1)
            {
                dfs(i, m - 1, vis, grid, delRow, delCol);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};