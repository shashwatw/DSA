//^ https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
//& Reference Video : https://www.youtube.com/watch?v=-uQGzhYj8BQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=38

//* ------------------------RECURSION---------------------------------------

// class Solution {
// private:
//     int solve(int ind, int buy, int cap, int n, vector<int>& prices) {
//         //base case
//         if(cap == 0) return 0;
//         if(ind == n) return 0;

//         int profit = 0;
//         if(buy)
//         {
//             profit = max(-prices[ind] + solve(ind+1, 0, cap, n, prices), 0 +
//             solve(ind+1, 1, cap, n, prices));
//         }
//         else
//         {
//             profit = max(prices[ind] + solve(ind+1, 1, cap-1, n, prices), 0 +
//             solve(ind+1, 0, cap, n, prices));
//         }
//         return profit;
//     }

// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         return solve(0, 1, 2, n, prices);
//     }
// };

//* ---------------------------------MEMOIZATION---------------------------------------

// class Solution {
// private:
//     int solve(int ind, int buy, int cap, int n, vector<int>& prices,
//     vector<vector<vector<int>>>& dp) {
//         //base case
//         if(cap == 0) return 0;
//         if(ind == n) return 0;
//         if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

//         int profit = 0;
//         if(buy)
//         {
//             profit = max(-prices[ind] + solve(ind+1, 0, cap, n, prices, dp),
//             0 + solve(ind+1, 1, cap, n, prices, dp));
//         }
//         else
//         {
//             profit = max(prices[ind] + solve(ind+1, 1, cap-1, n, prices, dp),
//             0 + solve(ind+1, 0, cap, n, prices, dp));
//         }
//         return dp[ind][buy][cap] = profit;
//     }

// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n, vector<vector<int>>(2,
//         vector<int>(3, -1))); return solve(0, 1, 2, n, prices, dp);
//     }
// };

//* ---------------------------------3D TABULATION---------------------------------------

// class Solution {
// public:
// int maxProfit(vector<int>& prices) {
//     int n = prices.size();
//     vector<vector<vector<int>>> dp(n + 1,
//                                    vector<vector<int>>(2, vector<int>(3, 0)));

//     // base case covered as we made whole 3D dp as 0
//     int profit = 0;

//     for (int ind = n - 1; ind >= 0; ind--) {
//         for (int buy = 0; buy <= 1; buy++) {
//             for (int cap = 1; cap <= 2; cap++) {
//                 if (buy) {
//                     profit = max(-prices[ind] + dp[ind + 1][0][cap],
//                                  0 + dp[ind + 1][1][cap]);
//                 } else {
//                     profit = max(prices[ind] + dp[ind + 1][1][cap - 1],
//                                  0 + dp[ind + 1][0][cap]);
//                 }
//                 dp[ind][buy][cap] = profit;
//             }
//         }
//     }
//     return dp[0][1][2];
// }
// };

//* ---------------------------------2D TABULATION---------------------------------------

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));

        // base case covered as we made whole 3D dp as 0
        int profit = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= 2; cap++)
                {
                    if (buy)
                    {
                        profit = max(-prices[ind] + ahead[0][cap],
                                     0 + ahead[1][cap]);
                    }
                    else
                    {
                        profit = max(prices[ind] + ahead[1][cap - 1],
                                     0 + ahead[0][cap]);
                    }
                    curr[buy][cap] = profit;
                }
            }
            ahead = curr;
        }
        return ahead[1][2];
    }
};