//^ https://leetcode.com/problems/longest-string-chain/
//* Reference Video : https://www.youtube.com/watch?v=YY8iBaYcc4g&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=48

// not much variation from LIS code just one cond check added at Line 50

class Solution
{
private:
    bool checkPossible(string &s1, string &s2)
    {
        if (s1.size() != s2.size() + 1)
            return false;
        int first = 0, second = 0;

        while (first < s1.size())
        {
            if (second < s2.size() && s1[first] == s2[second])
            {
                first++;
                second++;
            }
            else
            {
                first++;
            }
        }

        if (first == s1.size() && second == s2.size())
            return true;
        else
            return false;
    }

public:
    int longestStrChain(vector<string> &words)
    {
        auto comp = [](const string &s1, const string &s2)
        {
            return s1.size() < s2.size();
        };
        sort(words.begin(), words.end(), comp);
        int n = words.size();

        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (checkPossible(words[i], words[prev]) &&
                    1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                }
            }

            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};