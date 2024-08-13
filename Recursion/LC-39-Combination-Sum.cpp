//* https://leetcode.com/problems/combination-sum/description/
//! Reference Video: https://www.youtube.com/watch?v=OyZFFqQtu98&list=PLgUwDviBIf0rQ6cnlaHRMuOp4H_D-7hwP

class Solution
{
private:
    void findCombination(int ind, int target, vector<int> &candidates, vector<vector<int>> &res, vector<int> &ds)
    {
        if (ind == candidates.size())
        {
            if (target == 0)
            {
                res.push_back(ds);
            }
            return;
        }

        // pick
        if (candidates[ind] <= target)
        {
            ds.push_back(candidates[ind]);
            findCombination(ind, target - candidates[ind], candidates, res, ds);
            ds.pop_back();
        }

        // not pick
        findCombination(ind + 1, target, candidates, res, ds);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> ds;

        findCombination(0, target, candidates, res, ds);
        return res;
    }
};