//^ https://leetcode.com/problems/01-matrix/description/

//! This Question's reverse is GFG question naming : Distance of nearest cell having 1

//^ INTUITION for 01 Matrix
//* We need to get the nearest dist of 0 for each cell
//* We made a copy of mat naming vis and a same size dist matrix
//* now we initialise vis and dist as 0
//* In vis, we will make the vis[row][col] = 1 as and when we push it in queue
//* Now initially at all 0s the distance of 0 is 0 so we push it in q with dist as 0
//* While traversing queue, when we pop a pair we update dist matrix of that row and col to its step
//* Now we move all directions and check whether they have been vis or not
//* If not then we will push them and increment the prev step by 1 and push new unvis row col with this step in q
//* Now we make it vis and push it in queue

//* Finally after the queue is empty we will get the nearest 0 dist for each cell in dist matrix;

//& TC = SC = O(n*m)

//~ CODE (using BFS)

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<pair<int, int>, int>> q;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
                else
                {
                    vis[i][j] = 0;
                }
            }
        }

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();

            dist[row][col] = step;

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0)
                {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, step + 1});
                }
            }
        }
        return dist;
    }
};