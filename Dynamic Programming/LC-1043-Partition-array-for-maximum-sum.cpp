//^ https://leetcode.com/problems/partition-array-for-maximum-sum/description/
//& Reference Video : https://www.youtube.com/watch?v=PhWWJmaKfMc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=55

//* *****************************RECURSIVE****************************************

class Solution
{
private:
    int solve(int ind, int k, int n, vector<int> &arr)
    {
        if (ind == n)
            return 0;
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        for (int j = ind; j < min(n, ind + k); j++)
        {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = len * maxi + solve(j + 1, k, n, arr);
            maxAns = max(maxAns, sum);
        }
        return maxAns;
    }

public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();

        return solve(0, k, n, arr);
    }
};

//* ***************************MEMOIZATION********************************************
//& TC - O(n) x O(k)
//& SC - O(n) x O(n) -> Aux Stack space

class Solution
{
private:
    int solve(int ind, int k, int n, vector<int> &arr, vector<int> &dp)
    {
        if (ind == n)
            return 0;
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;

        if (dp[ind] != -1)
            return dp[ind];

        for (int j = ind; j < min(n, ind + k); j++)
        {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = len * maxi + solve(j + 1, k, n, arr, dp);
            maxAns = max(maxAns, sum);
        }
        return dp[ind] = maxAns;
    }

public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        return solve(0, k, n, arr, dp);
    }
};

//* ***************************TABULATION********************************************
//& TC - O(n) x O(k)
//& SC - O(n)

class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int ind = n - 1; ind >= 0; ind--)
        {
            int len = 0;
            int maxi = INT_MIN;
            int maxAns = INT_MIN;

            for (int j = ind; j < min(n, ind + k); j++)
            {
                len++;
                maxi = max(maxi, arr[j]);
                int sum = len * maxi + dp[j + 1];
                maxAns = max(maxAns, sum);
            }
            dp[ind] = maxAns;
        }
        return dp[0];
    }
};