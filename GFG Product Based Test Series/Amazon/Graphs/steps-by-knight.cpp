//* https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-graphs/problem/steps-by-knight5927

class Solution
{
public:
    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        // Direction vectors for the knight's movement
        int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
        int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

        // Initialize the visited array
        vector<vector<bool>> vis(N, vector<bool>(N, false));

        // Queue for BFS which stores {current position, current steps}
        queue<pair<pair<int, int>, int>> q;

        // Adjusting from 1-based to 0-based indexing
        int startX = KnightPos[0] - 1;
        int startY = KnightPos[1] - 1;
        int endX = TargetPos[0] - 1;
        int endY = TargetPos[1] - 1;

        // Starting position
        q.push({{startX, startY}, 0});
        vis[startX][startY] = true;

        while (!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            // If the current position is the target position, return the number of steps
            if (x == endX && y == endY)
            {
                return steps;
            }

            // Explore all possible moves of the knight
            for (int i = 0; i < 8; i++)
            {
                int fx = x + dx[i];
                int fy = y + dy[i];

                // Check if the new position is within bounds and not visited
                if (fx >= 0 && fx < N && fy >= 0 && fy < N && !vis[fx][fy])
                {
                    vis[fx][fy] = true;
                    q.push({{fx, fy}, steps + 1});
                }
            }
        }

        // If the target position is not reachable, return -1
        return -1;
    }
};