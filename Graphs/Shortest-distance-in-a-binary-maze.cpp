//^ https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1

//* INTUITION

//* We will go for Q here as PQ will take logarithmic TC to fetch smallest and anyways queue will always give same order as every cell has unit and equal distance
//* Then we will make q queue for {distance from source, {row, col}} format
//* Then we will do iterations as below ans when we encounter our destination node in queue we will return dis + 1;

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        // code here
        if (source.first == destination.first && source.second == destination.second)
            return 0;

        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        dist[source.first][source.second] = 0;

        q.push({0, {source.first, source.second}});

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 &&
                    dist[nrow][ncol] > dis + 1)
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
        return -1;
    }
};