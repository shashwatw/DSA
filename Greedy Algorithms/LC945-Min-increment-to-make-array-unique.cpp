//*https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/

class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        sort(nums.begin(), nums.end());

        int cnt = 0;        // This will store the number of increments
        int prev = nums[0]; // Initialize the previous element as the first element

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] <= prev)
            {
                cnt += (prev + 1 - nums[i]);
                prev++;
            }
            else
            {
                prev = nums[i];
            }
        }

        return cnt;
    }
};