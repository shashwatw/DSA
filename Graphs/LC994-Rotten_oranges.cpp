//^https://leetcode.com/problems/rotting-oranges/description/

//& INTUITION
//* Initially we wanted that all the oranges should be rotten levelwise - > BFS is the only feasible approach
//* Now we made a copy vis matrix of grid's size
//* And a queue of pair<pair<int>> to store row, col and t (Level or time)
//* then when we found the cell as 2 we push it into queue and make the vis that row and col as 2
//* If its not a rotten orange we marked it as 0;
//* Made delrow and delcol for all the four neighbours traversal
//* started bfs call
//* while popping front of q we maintained a time variable checking max level or t encountered till now in q
//* pushing the elements if they are fresh  with a lvl increment (or t inc)
//* If we call bfs call we make that vis[row][col] as 2
//* Finally just check that whether any fresh orange is not left in our vis --> if left --> return -1
//* else return time

//& Space Complexity - O(n*m)
//& Time Complexity - O(n*m)

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        int vis[n][m];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else
                {
                    vis[i][j] = 0;
                }
            }
        }

        int time = 0;

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            time = max(time, t);
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
                {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] != 2 && grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return time;
    }
};