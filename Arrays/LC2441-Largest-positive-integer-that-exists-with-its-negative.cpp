//^ https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/

class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        if (unique(nums.begin(), nums.end()) == nums.begin() + 1)
        {
            return -1;
        }

        sort(nums.begin(), nums.end());

        int i = 0;
        int j = nums.size() - 1;

        while (i < j)
        {
            if (abs(nums[i]) == nums[j])
            {
                return nums[j];
            }

            if (abs(nums[i]) < nums[j])
            {
                --j;
            }
            else
            {
                ++i;
            }
        }
        return -1;
    }
};
