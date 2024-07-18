//^ https://www.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1
//& Here only tabulation is passing due to time constraints

//*************************************************RECURSIVE******************************************************* */
class Solution
{
private:
    int solve(int curr, int prev, vector<int> &arr, int n, bool isIncreasing)
    {
        if (curr == n)
            return 0;

        int take = 0, notTake = 0;

        if (prev == -1 || (isIncreasing && arr[curr] > arr[prev]) || (!isIncreasing && arr[curr] < arr[prev]))
        {
            take = 1 + solve(curr + 1, curr, arr, n, !isIncreasing);
        }

        notTake = solve(curr + 1, prev, arr, n, isIncreasing);

        return max(take, notTake);
    }

public:
    int alternatingMaxLength(vector<int> &arr)
    {
        // Code here
        int n = arr.size();
        return max(solve(0, -1, arr, n, true), solve(0, -1, arr, n, false));
    }
};

//*************************************************MEMOIZE******************************************************* */
class Solution
{
private:
    int solve(int curr, int prev, vector<int> &arr, int n, bool isIncreasing, vector<vector<vector<int>>> &dp)
    {
        if (curr == n)
            return 0;

        if (dp[curr][prev + 1][isIncreasing] != -1)
            return dp[curr][prev + 1][isIncreasing];

        int take = 0, notTake = 0;

        if (prev == -1 || (isIncreasing && arr[curr] > arr[prev]) || (!isIncreasing && arr[curr] < arr[prev]))
        {
            take = 1 + solve(curr + 1, curr, arr, n, !isIncreasing, dp);
        }

        notTake = solve(curr + 1, prev, arr, n, isIncreasing, dp);

        return dp[curr][prev + 1][isIncreasing] = max(take, notTake);
    }

public:
    int alternatingMaxLength(vector<int> &arr)
    {
        // Code here
        int n = arr.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        return max(solve(0, -1, arr, n, true, dp), solve(0, -1, arr, n, false, dp));
    }
};

//************************************************TABULATION******************************************************* */
class Solution
{
public:
    int alternatingMaxLength(vector<int> &arr)
    {
        // Code here
        int n = arr.size();
        if (n == 0)
            return 0;

        // Initialize the DP table with dimensions (n+1) x 2
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(2, 0)));

        // Fill the DP table
        for (int i = n - 1; i >= 0; --i)
        {
            for (int prev_taken = 0; prev_taken <= 1; ++prev_taken)
            {
                for (int isIncreasing = 0; isIncreasing <= 1; ++isIncreasing)
                {
                    int take = 0;
                    int notTake = dp[i + 1][prev_taken][isIncreasing];

                    if (!prev_taken || (isIncreasing && arr[i] > arr[i - prev_taken]) || (!isIncreasing && arr[i] < arr[i - prev_taken]))
                    {
                        take = 1 + dp[i + 1][1][!isIncreasing];
                    }

                    dp[i][prev_taken][isIncreasing] = max(take, notTake);
                }
            }
        }

        return max(dp[0][0][1], dp[0][0][0]);
    }
};