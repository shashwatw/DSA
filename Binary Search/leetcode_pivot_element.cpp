class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int sum = 0, sum2 = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        for (int i = 0; i < nums.size(); i++)
        {
            if (sum - nums[i] == 2 * sum2)
                return i;
            sum2 += nums[i];
        }
        return -1;
    }
};