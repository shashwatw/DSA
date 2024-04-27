//^ https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1

//! Intuition
//* We will we storing all the cordinates of the islands in a vector after subtracting them from a base case
//* Now we will push this vector consisting all the cordinates of islands into as set
//* As set will only store unique vectors
//* We can obtain number of unique islands using ste's size

//& Approach 1 (Using DFS)

//~ CODE:
class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &vec, int row0, int col0)
    {
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;

        vec.push_back({row - row0, col - col0});

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                dfs(nrow, ncol, vis, grid, vec, row0, col0);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        // code here
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int, int>> vec;
                    dfs(i, j, vis, grid, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};

//^ Approach 2 (Using BFS)

// User function Template for C++

class Solution
{
private:
    void bfs(int r, int c, vector<vector<int>> &matrix, vector<vector<int>> &vis, vector<pair<int, int>> &ans)
    {
        vis[r][c] = 1;
        int m = matrix.size();
        int n = matrix[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            ans.push_back({r - row, c - col});
            q.pop();
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int newrow = row + drow[i];
                int newcol = col + dcol[i];
                if (newrow >= 0 and newcol >= 0 and newrow < m and newcol < n and matrix[newrow][newcol] == 1 and !vis[newrow][newcol])
                {
                    q.push({newrow, newcol});
                    vis[newrow][newcol] = 1;
                }
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &matrix)
    {
        // code here
        int m = matrix.size();
        int n = matrix[0].size();
        set<vector<pair<int, int>>> st;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] and matrix[i][j] == 1)
                {
                    vector<pair<int, int>> ans;
                    bfs(i, j, matrix, vis, ans);
                    st.insert(ans);
                }
            }
        }
        return st.size();
    }
};