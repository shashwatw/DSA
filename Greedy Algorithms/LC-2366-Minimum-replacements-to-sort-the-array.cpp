//^ https://leetcode.com/problems/minimum-replacements-to-sort-the-array/description/

class Solution
{
public:
    long long minimumReplacement(vector<int> &nums)
    {
        long long maxi = nums.back();
        long long res = 0;

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            long long op = (nums[i] - 1) / maxi;
            res += op;
            maxi = nums[i] / (op + 1);
        }
        return res;
    }
};