//^ https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

//* Intuition:
//^ Initially we will think of base case
//^ When we we will reach the end then no profit returned if something is in hand bought
//^ initialise variable 'buy' for telling whther next is to be bought or sold...if bought then buy = 1 else 0
//^ Use Take or not take principle of recursion
//^ if we buy, then subtract the bought value from profit and while selling add the selling value in profit
//^ Finally return the maxprofit

//* --------------------------RECURSION---------------------------------------------------
//& TC - O(2^n);
//& SC - O(n)

// class Solution {
// private:
//     int solve(int ind, int buy, int N, vector<int>& prices) {

//         // base case
//         if (ind == N)
//             return 0;

//         long profit = 0;
//         if (buy) {
//             profit = max((-prices[ind] + solve(ind + 1, 0, N, prices)),
//                          (0 + solve(ind + 1, 1, N, prices)));
//         } else {
//             profit = max((prices[ind] + solve(ind + 1, 1, N, prices)),
//                          0 + (0 + solve(ind + 1, 0, N, prices)));
//         }
//         return profit;
//     }

// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         return solve(0, 1, n, prices);
//     }
// };

//* --------------------------MEMOIZATION---------------------------------------------------
//& TC - O(n*2);
//& SC - O(n*2) + O(n)

// class Solution {
// private:
//     int solve(int ind, int buy, int N, vector<int>& prices,
//     vector<vector<int>>& dp) {

//         // base case
//         if (ind == N)
//             return 0;

//             if(dp[ind][buy] != -1) return dp[ind][buy];

//         long profit = 0;
//         if (buy) {
//             profit = max((-prices[ind] + solve(ind + 1, 0, N, prices, dp)),
//                          (0 + solve(ind + 1, 1, N, prices, dp)));
//         } else {
//             profit = max((prices[ind] + solve(ind + 1, 1, N, prices, dp)),
//                          0 + (0 + solve(ind + 1, 0, N, prices, dp)));
//         }
//         return dp[ind][buy] = profit;
//     }

// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n, vector<int>(2, -1));
//         return solve(0, 1, n, prices, dp);
//     }
// };

//* --------------------------TABULATION---------------------------------------------------
//& TC - O(n*2)
//& SC - O(n*2)

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n + 1, vector<int>(2, 0));

//         // base case
//         dp[n][0] = dp[n][1] = 0;

//         for (int ind = n - 1; ind >= 0; ind--) // as recur went 0 to n-1 so tab is reverse
//         {
//             for (int buy = 1; buy >= 0; buy--) {
//                 long profit = 0;
//                 if (buy) {
//                     profit =
//                         max(-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
//                 } else {
//                 profit = max(prices[ind] + dp[ind+1][1],
//                              0 + dp[ind+1][0]);
//                 }
//                 dp[ind][buy] = profit;
//             }
//         }
//         return dp[0][1];
//     }
// };

//* --------------------------1D Space Optimized TABULATION-------------------------------
//& TC - O(n*2)
//& SC - O(2n)

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2, 0);

        // base case
        ahead[0] = ahead[1] = 0;

        for (int ind = n - 1; ind >= 0; ind--) // as recur went 0 to n-1 so tab is reverse
        {
            for (int buy = 1; buy >= 0; buy--)
            {
                long profit = 0;
                if (buy)
                {
                    profit =
                        max(-prices[ind] + ahead[0], 0 + ahead[1]);
                }
                else
                {
                    profit = max(prices[ind] + ahead[1],
                                 0 + ahead[0]);
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }
};