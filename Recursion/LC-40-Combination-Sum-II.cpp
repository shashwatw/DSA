//* https://leetcode.com/problems/combination-sum-ii/

class Solution
{
private:
    void findCombination(int ind, int target, vector<int> &candidates, vector<vector<int>> &res, vector<int> &ds)
    {
        if (target == 0)
        {
            res.push_back(ds);
            return;
        }

        for (int i = ind; i < candidates.size(); i++)
        {
            // Skip duplicates
            if (i > ind && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            ds.push_back(candidates[i]);
            findCombination(i + 1, target - candidates[i], candidates, res, ds);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> ds;

        sort(candidates.begin(), candidates.end());
        findCombination(0, target, candidates, res, ds);

        return res;
    }
};
