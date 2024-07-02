// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150

//^ ----------------------------------------------------APPROACH 1 (Striver)--------------------------------------------------

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mini = prices[0];
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit, cost);
            mini = min(mini, prices[i]);
        }
        return maxProfit;
    }
};

//^ ----------------------------------------------------APPROACH 2--------------------------------------------------------------
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
        {
            return 0;
        }

        int buy = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < n; i++)
        {
            if (prices[i] < buy)
            {
                buy = prices[i];
            }
            else
            {
                int profit = prices[i] - buy;
                if (profit > maxProfit)
                {
                    maxProfit = profit;
                }
            }
        }

        return maxProfit;
    }
};
