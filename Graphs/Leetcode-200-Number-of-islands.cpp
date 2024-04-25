//^ https://leetcode.com/problems/number-of-islands/description/
//& In leetcode Neighbours are considered as Connected in 4 Directions *** IMPORTANT

//* Steps of understanding

//* Firstly we go intuition that it is a matrix
//* we will create a vis matrix and initialise with 0
//* Traverse through each and every element of matrix and checking for water/land or !vis
//* If not visited inc cnt and call bfs
//* In bfs, firstly create a queue of pair<int,int> to store row and col
//* Make vis[row][col] as 1
//* push first starting point to q
//* Run while loop till q gets empty
//* pop the q element and check for its 8 neighbours using the trick
//* if both row and col are getting updated that means its diagnol direcn and we do not want diagnol direns
//* So we skip remaining iteration when diagnol directions come and iterate only when primary(up, down, right, left) dirns found
//* Check for basic conditions such as validity, not visited and land
//* Complete bfs

//? Space complexity - O(n^2) + O(n^2) {for vis matrix and queue worst space}
//? Time Complexity - O(n^2) * 8 neighbours { Worst case if all 1s in matrix}

//^ TC - O(n^2)
//^ SC - O(n^2)

//~ CODE using BFS:
class Solution
{

private:
    void bfs(int row, int col, vector<vector<int>> &vis,
             vector<vector<char>> &grid)
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

            //! traversing all 8 neighbours
            for (int delrow = -1; delrow <= 1; delrow++)
            {
                for (int delcol = -1; delcol <= 1; delcol++)
                {
                    int nrow = rows + delrow;
                    int ncol = cols + delcol;

                    //! Here are skipping this considering that if both nrow
                    //! ncol are changing means its diagnol directions.
                    //! In leetcode only 4 directions are considered so
                    //! Whenever we encounter directional change
                    //! we will skip remaining iteraion of loop and move forward.
                    if (delrow != 0 && delcol != 0)
                    {
                        continue;
                    }

                    //! checking validity, vis and land
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                        !vis[nrow][ncol] && grid[nrow][ncol] == '1')
                    {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

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