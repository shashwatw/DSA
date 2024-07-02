//* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
//^ Reference Video : https://www.youtube.com/watch?v=IGIe46xw3YY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=40

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(
            n + 2, vector<int>(2, 0)); // n+2 to eradicate runtime error

        // base case
        dp[n][0] = dp[n][1] = 0;

        for (int ind = n - 1; ind >= 0;
             ind--) // as recur went 0 to n-1 so tab is reverse
        {
            for (int buy = 1; buy >= 0; buy--)
            {
                long profit = 0;
                if (buy)
                {
                    profit =
                        max(-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
                }
                else
                {
                    profit =
                        max(prices[ind] + dp[ind + 2][1], 0 + dp[ind + 1][0]);
                    // here move to ind+2 if sold as there is cooldown right next to
                    // sold one
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};