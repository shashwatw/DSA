//* https://leetcode.com/problems/subsets/description/

class Solution
{
public:
    void solve(vector<int> &nums, int index, vector<int> &current,
               vector<vector<int>> &res)
    {
        if (index == nums.size())
        {
            res.push_back(current);
            return;
        }

        // Exclude the current element
        solve(nums, index + 1, current, res);

        // Include the current element
        current.push_back(nums[index]);
        solve(nums, index + 1, current, res);
        current.pop_back();
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> current;
        solve(nums, 0, current, res);
        return res;
    }
};
