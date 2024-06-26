//* https://www.geeksforgeeks.org/problems/scrambled-string/1
//& Reference Video : https://www.youtube.com/watch?v=SqA0o-DGmEw&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=40

//^ Approach :
//* Basically we have to make a Binary Tree sort of structure and swap any pairs
//* Now here we exactly do not know from where to swap therefore we will try to swap after each index...starting from 1 as we can swap empty string
//* Now for each index we have two options either to swap or not to swap
//* We will write 2 conditions which will check the strings recursively and if any of it becomes true which means we reached scramble string or the given string is scrambled string

//* ----------------------RECURSIVE APPROACH ------------------------------------------------------------------------------------

class Solution
{
private:
    bool solve(string s1, string s2)
    {
        if (s1.compare(s2) == 0)
            return true;
        if (s1.size() <= 1)
            return false;

        int n = s1.size();
        bool flag = false;

        for (int i = 1; i <= n - 1; i++)
        {
            if ((solve(s1.substr(0, i), s2.substr(n - i, i)) && solve(s1.substr(i, n - i), s2.substr(0, n - i))) ||
                (solve(s1.substr(0, i), s2.substr(0, i)) && solve(s1.substr(i, n - i), s2.substr(i, n - i))))
            {
                flag = true;
                break;
            }
        }
        return flag;
    }

public:
    bool isScramble(string s1, string s2)
    {
        // code here
        if (s1.size() != s2.size())
            return false;
        if (s1.size() == 0 && s2.size() == 0)
            return true;

        return solve(s1, s2);
    }
};

//* ----------------------MEMOIZED APPROACH ------------------------------------------------------------------------------------

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
            if ((solve(s1.substr(0, i), s2.substr(n - i, i)) && solve(s1.substr(i, n - i), s2.substr(0, n - i))) ||
                (solve(s1.substr(0, i), s2.substr(0, i)) && solve(s1.substr(i, n - i), s2.substr(i, n - i))))
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
        // code here
        if (s1.size() != s2.size())
            return false;
        if (s1.size() == 0 && s2.size() == 0)
            return true;

        return solve(s1, s2);
    }
};
