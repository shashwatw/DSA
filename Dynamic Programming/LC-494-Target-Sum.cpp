//* This problem is exact same as
//* https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

//* Now here instead of writing + and - signs what we are doing is
//* making two groups of subsets

//* One group has numbers which have + sign other group with -ve signs
//* That Means if we instead of all this think of dividing in two groups
//* And diff of the two groups to return target
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int sum = 0;

        for (int it : nums)
            sum += it;

        //* ODD range case
        if ((sum + target) % 2 != 0 || sum < abs(target))
            return 0;

        int range = (sum + target) / 2;

        vector<vector<int>> tab(n + 1, vector<int>(range + 1, 0));

        tab[0][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= range; j++)
            {
                if (nums[i - 1] <= j)
                {
                    tab[i][j] = tab[i - 1][j - nums[i - 1]] + tab[i - 1][j];
                }
                else
                {
                    tab[i][j] = tab[i - 1][j];
                }
            }
        }

        return tab[n][range];
    }
};