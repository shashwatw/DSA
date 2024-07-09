//* https://leetcode.com/problems/average-waiting-time/
//^ https://www.youtube.com/watch?v=MhY6x3h0t3o

class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        long busyUptill = 0, n = customers.size(), waitingTime = 0;

        for (int i = 0; i < n; i++)
        {
            long arrival = customers[i][0], time = customers[i][1];
            waitingTime += max(arrival, busyUptill) + time - arrival;
            busyUptill = max(arrival, busyUptill) + time;
        }
        return (waitingTime * 1.0) / n;
    }
};