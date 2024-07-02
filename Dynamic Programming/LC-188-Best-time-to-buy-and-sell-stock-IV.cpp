//* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1,
                                       vector<vector<int>>(2, vector<int>(k + 1, 0)));

        // base case covered as we made whole 3D dp as 0
        int profit = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= k; cap++)
                {
                    if (buy)
                    {
                        profit = max(-prices[ind] + dp[ind + 1][0][cap],
                                     0 + dp[ind + 1][1][cap]);
                    }
                    else
                    {
                        profit = max(prices[ind] + dp[ind + 1][1][cap - 1],
                                     0 + dp[ind + 1][0][cap]);
                    }
                    dp[ind][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};