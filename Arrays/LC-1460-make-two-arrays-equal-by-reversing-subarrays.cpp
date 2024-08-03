//* https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays

class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        if (target.size() != arr.size())
            return false;
        map<int, int> mp;
        for (auto it : target)
        {
            mp[it]++;
        }

        for (auto it : arr)
        {
            if (mp.find(it) == mp.end() || mp[it] == 0)
            {
                return false;
            }
            mp[it]--;
        }

        for (auto iter : mp)
        {
            if (iter.second != 0)
                return false;
        }
        return true;
    }
};