//* https://leetcode.com/problems/scramble-string/description/

class Solution
{
    unordered_map<string, bool> dp;

private:
    bool solve(string s1, string s2)
    {
        if (s1.compare(s2) == 0)
            return true;
        if (s1.size() <= 1)
            return false;

        int n = s1.size();
        bool flag = false;

        string key = s1;
        key.push_back(' ');
        key.append(s2);

        if (dp.find(key) != dp.end())
        {
            return dp[key];
        }

        for (int i = 1; i <= n - 1; i++)
        {
            if ((solve(s1.substr(0, i), s2.substr(n - i, i)) &&
                 solve(s1.substr(i, n - i), s2.substr(0, n - i))) ||
                (solve(s1.substr(0, i), s2.substr(0, i)) &&
                 solve(s1.substr(i, n - i), s2.substr(i, n - i))))
            {
                flag = true;
                break;
            }
        }
        return dp[key] = flag;
    }

public:
    bool isScramble(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return false;
        if (s1 == s2)
            return true;

        return solve(s1, s2);
    }
};