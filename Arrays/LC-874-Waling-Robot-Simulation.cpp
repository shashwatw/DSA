//* https://leetcode.com/problems/walking-robot-simulation/description/
class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        set<pair<int, int>> obstacleSet;
        for (auto obstacle : obstacles)
        {
            obstacleSet.insert({obstacle[0], obstacle[1]});
        }

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<int> currentPosition = {0, 0};
        int maxDistanceSquared = 0;
        int currentDirection = 0; // 0 - North, 1 - East, 2 - South, 3 - West

        for (int command : commands)
        {
            if (command == -1)
            {
                // turn right
                currentDirection = (currentDirection + 1) % 4;
                continue;
            }
            if (command == -2)
            {
                // turn left
                currentDirection = (currentDirection + 3) % 4;
                continue;
            }

            // Move forward and add posns
            vector<int> direction = directions[currentDirection];
            for (int step = 0; step < command; step++)
            {
                int nextX = currentPosition[0] + direction[0];
                int nextY = currentPosition[1] + direction[1];
                if (obstacleSet.find({nextX, nextY}) != obstacleSet.end())
                {
                    break;
                }
                currentPosition[0] = nextX;
                currentPosition[1] = nextY;
            }

            maxDistanceSquared =
                max(maxDistanceSquared,
                    (currentPosition[0] * currentPosition[0]) +
                        (currentPosition[1] * currentPosition[1]));
        }

        return maxDistanceSquared;
    }
};