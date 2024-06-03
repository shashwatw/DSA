//* https://leetcode.com/problems/find-the-duplicate-number/

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size() - 1;

        int x = n + 1;
        int res = 0;

        for (int i = 0; i < n + 1; i++)
        {
            int r = nums[i] % x;

            if (nums[r] / x > 0)
            {
                return r;
            }
            else
            {
                nums[r] += x;
            }
        }
        return -1;
    }
};