//* https://leetcode.com/problems/is-subsequence/

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int m = s.size();
        int n = t.size();

        int j = 0; // pointer for s

        for (int i = 0; i < n && j < m; i++)
        {
            if (s[j] == t[i])
            {
                j++;
            }
        }

        return j == m;
    }
};