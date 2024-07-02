//* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // base case
        dp[n][0] = dp[n][1] = 0;

        for (int ind = n - 1; ind >= 0; ind--) // as recur went 0 to n-1 so tab is reverse
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
                    // here we can either sub fee when transaction finished
                    // or can sub fee from profit upfront in buying
                    // Only subtract fee one time from profit either while buying or selling
                    profit = max(prices[ind] - fee + dp[ind + 1][1],
                                 0 + dp[ind + 1][0]);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};