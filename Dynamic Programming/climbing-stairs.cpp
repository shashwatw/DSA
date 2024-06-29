// https://leetcode.com/problems/climbing-stairs

class Solution
{
public:
    // 1+2+3+5+8+13
    //  vector<int> arr={0};
    int climbStairs(int n)
    {

        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < n + 1; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};