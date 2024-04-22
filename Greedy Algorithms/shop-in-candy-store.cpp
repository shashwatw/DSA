//! https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        int minCost = 0;
        int maxCost = 0;
        vector<int> ans;

        sort(candies, candies + N);

        int buy = 0;
        int freeC = N - 1;

        while (buy <= freeC)
        {
            minCost += candies[buy++];
            freeC -= K;
        }

        freeC = 0;
        buy = N - 1;

        while (freeC <= buy)
        {
            maxCost += candies[buy--];
            freeC += K;
        }

        ans.push_back(minCost);
        ans.push_back(maxCost);

        return ans;
    }
};