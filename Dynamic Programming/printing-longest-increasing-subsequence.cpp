//* https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/0
//^  Reference Video :https://www.youtube.com/watch?v=IFfYfonAFGc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=43

class Solution
{
public:
    vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
    {
        // Code here
        vector<int> dp(n, 1), hash(n);
        int maxi = 1;
        int lastIndex = 0;

        for (int i = 0; i < n; i++)
        {
            hash[i] = i;

            for (int prev = 0; prev < i; prev++)
            {
                if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev; // concept of backtracking
                }
            }
            if (dp[i] > maxi)
            {
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<int> temp;
        temp.push_back(arr[lastIndex]);

        while (hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);
        }

        reverse(temp.begin(), temp.end());
        return temp;
    }
};