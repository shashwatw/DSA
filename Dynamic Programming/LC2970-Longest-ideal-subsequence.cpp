//^ https://leetcode.com/problems/longest-ideal-subsequence/description/
//* Approach
//* Here to optimize space what we are trying to do is make a array where each index denotes each alphabet that is a to z
//* Now increment the index of that character by checking the right K indices and left K indices max value
//* Now increment 1 to that max value for the obtained character of iteration
//* Finally return the maxm value from the 26 size array

//~ CODE:
class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        int N = size(s);
        vector<int> dp(26, 0);

        int res = 0;
        // Updating dp with the i-th character
        for (int i = 0; i < N; i++)
        {
            int curr = s[i] - 'a';
            int best = 0;
            for (int prev = 0; prev < 26; prev++)
            {
                if (abs(prev - curr) <= k)
                {
                    best = max(best, dp[prev]);
                }
            }

            // Appending s[i] to the previous longest ideal subsequence allowed
            dp[curr] = max(dp[curr], best + 1);
            res = max(res, dp[curr]);
        }
        return res;
    }
};