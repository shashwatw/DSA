// https://leetcode.com/problems/longest-consecutive-sequence/description/

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int longestStreak = 1;
        int currentStreak = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                if (nums[i] == nums[i - 1] + 1)
                {
                    currentStreak++;
                }
                else
                {
                    longestStreak = max(longestStreak, currentStreak);
                    currentStreak = 1;
                }
            }
        }

        return max(longestStreak, currentStreak);
    }
};