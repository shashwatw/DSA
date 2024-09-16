//* https://leetcode.com/problems/minimum-time-difference/description/?envType=daily-question&envId=2024-09-16

class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        vector<int> minutes;
        for (auto time : timePoints)
        {
            int hrs = stoi(time.substr(0, 2)) * 60;
            int mins = stoi(time.substr(3, 2));

            minutes.push_back(hrs + mins);
        }

        sort(minutes.begin(), minutes.end());

        int mini = INT_MAX;

        for (int i = 1; i < minutes.size(); i++)
        {
            mini = min(mini, (minutes[i] - minutes[i - 1]));
        }

        int n = minutes.size();

        mini = min(mini, (1440 - minutes[n - 1] + minutes[0]));

        return mini;
    }
};