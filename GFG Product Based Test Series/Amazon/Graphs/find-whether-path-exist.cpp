//* https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-graphs/problem/find-whether-path-exist5238

class Solution
{
public:
    bool dfs(int rsrc, int csrc, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();

        vis[rsrc][csrc] = 1;

        // Check for the destination cell (value 2)
        if (grid[rsrc][csrc] == 2)
        {
            return true;
        }

        // Possible movements: up, right, down, left
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // Explore all 4 possible directions
        for (int i = 0; i < 4; i++)
        {
            int newRow = rsrc + delRow[i];
            int newCol = csrc + delCol[i];

            // Check if the new cell is within the grid and not visited
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                !vis[newRow][newCol] && grid[newRow][newCol] != 0)
            {

                if (dfs(newRow, newCol, grid, vis))
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool is_Possible(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Find the source cell (value 1) and start DFS
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    if (dfs(i, j, grid, vis))
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        return false; // If no source cell is found
    }
};