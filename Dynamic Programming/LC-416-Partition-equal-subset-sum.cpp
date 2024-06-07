//*https://leetcode.com/problems/partition-equal-subset-sum/

class Solution
{
private:
    bool subsetSum(vector<int> &nums, int sum)
    {
        int n = nums.size();
        vector<vector<bool>> tab(n + 1, vector<bool>(sum + 1, false));

        for (int i = 0; i <= n; i++)
        {
            tab[i][0] = true;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (nums[i - 1] <= j)
                {
                    tab[i][j] = tab[i - 1][j - nums[i - 1]] || tab[i - 1][j];
                }
                else
                {
                    tab[i][j] = tab[i - 1][j];
                }
            }
        }
        return tab[n][sum];
    }

public:
    bool canPartition(vector<int> &nums)
    {

        int sum = 0;
        for (auto it : nums)
        {
            sum += it;
        }
        // agar odd hoga toh not possible to break in two equal halves therefore
        // return false
        if (sum % 2 != 0)
            return false;

        // If even sum than find for a subset of sum/2 in subset as array adding
        // up to sum/2 if are present then remaining will also make sum/2
        // therefore it should return true
        return subsetSum(nums, sum / 2);
    }
};