class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int i = 0, j = 0;
        int n = nums.size() - 1;
        while (i <= n && j <= n)
        {
            if (nums[j] != 0)
            {
                swap(nums[j++], nums[i]);
                i++;
            }
            else
            {
                j++;
            }
        }
    }
};