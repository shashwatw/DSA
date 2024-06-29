//*https://leetcode.com/problems/house-robber/

//^ -------------------------------RECURSIVE------------------------------------------------
// & TC - O(n)

class Solution
{
private:
    int solve(vector<int> &nums, int ind)
    {
        if (ind < 0)
            return 0; // Base case for negative index

        // Recurrence relation: either pick the current house or don't
        int pick = nums[ind] + solve(nums, ind - 2);
        int notPick = solve(nums, ind - 1);

        // Return the maximum of picking or not picking the current house
        return max(pick, notPick);
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        return solve(nums, n - 1); // Start solving from the last house
    }
};

//^ -------------------------------MEMOIZED------------------------------------------------
