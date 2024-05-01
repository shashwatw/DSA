//^ https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

//* INTUITION
//* We want to find the shortest path from [0][0] to [n-1][n-1] source and dest are fixed as told
//* Now here if we are already at destination we are considering it as 1 (path-1);
//* Now what we can do is perform dijktra algo and initialise a queue with below in code stated structure
//* In there we will push initial dist as 1 and source 0,0
//* Now untill while loop if empty we will check all its neighbours (8) and check for their dist in dist[]
//* Initially only source has distance of initial 1 units
//* Other will have infinity
//* as and when we encounter a distance that is lesser than dist[nrow][ncol] we will update it
//* Finally we will check that whether the nrow and ncol are destination nodes as we want to reach them
//* The moment we reach them we will return dis + 1 as it takes 1 unit to reach to them... if not found push rows and cols with new dist from source
//* At some moment if we reach ans will be returned else -1 will be returned

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();

        pair<int, int> destination;
        destination.first = n - 1;
        destination.second = n - 1;

        //[{1}] wala case
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
        {
            return -1;
        }

        //[{0}] wala case
        if (destination.first == 0 && destination.second == 0)
            return 1;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        dist[0][0] = 1;

        queue<pair<int, pair<int, int>>> q;

        q.push({1, {0, 0}});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for (int delRow = -1; delRow <= 1; delRow++)
            {
                for (int delCol = -1; delCol <= 1; delCol++)
                {
                    int nrow = row + delRow;
                    int ncol = col + delCol;

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                        grid[nrow][ncol] == 0 && dist[nrow][ncol] > dis + 1)
                    {
                        dist[nrow][ncol] = dis + 1;

                        if (nrow == destination.first && ncol == destination.second)
                        {
                            return dis + 1;
                        }

                        q.push({dis + 1, {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
    }
};
