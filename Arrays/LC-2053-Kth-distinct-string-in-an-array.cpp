//* https://leetcode.com/problems/kth-distinct-string-in-an-array

class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        unordered_map<string, int> mp;
        for (auto it : arr)
        {
            mp[it]++;
        }
        int f = 0;
        for (auto it : arr)
        {
            if (mp[it] == 1)
            {
                f++;
                if (k == f)
                {
                    return it;
                }
            }
        }
        return "";
    }
};