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

// O(n) TC

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> num_set(nums.begin(), nums.end());

        int longestStreak = 0;

        for (int num : num_set)
        {
            if (num_set.find(num - 1) == num_set.end())
            {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.find(currentNum + 1) != num_set.end())
                {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};