//* https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

// User function template for C++

//* RECURSIVE APPROACH

class Solution
{
private:
    bool solve(vector<int> &arr, int n, int sum)
    {
        if (sum == 0)
            return true;
        if (n == 0)
            return false;

        if (arr[n - 1] <= sum)
        {
            return solve(arr, n - 1, sum - arr[n - 1]) || solve(arr, n - 1, sum);
        }
        else
        {
            return solve(arr, n - 1, sum);
        }
    }

public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        // code here
        int n = arr.size();
        return solve(arr, n, sum);
    }
};

//* MEMOIZED APPROACH

// User function template for C++

class Solution
{
private:
    bool solve(vector<int> &arr, int n, int sum, vector<vector<int>> &dp)
    {
        if (sum == 0)
            return true;
        if (n == 0)
            return false;

        if (dp[n][sum] != -1)
            return dp[n][sum];

        if (arr[n - 1] <= sum)
        {
            dp[n][sum] = solve(arr, n - 1, sum - arr[n - 1], dp) || solve(arr, n - 1, sum, dp);
        }
        else
        {
            dp[n][sum] = solve(arr, n - 1, sum, dp);
        }
        return dp[n][sum];
    }

public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        // code here
        int n = arr.size();

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return solve(arr, n, sum, dp);
    }
};

//* TABULATION METHOD

class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        //^ code here
        //^ Using Knapsack logic
        //^ Wt[] there ---> arr[] here
        //^ val[] there ----> ignore
        //^ W there -------> sum here

        //^ Tabulation --> DP

        int n = arr.size();

        //^ [i][j] intable [i] represents arr size and [j] represents sum or target
        //^ Initial table has [0][0] as true...as 0 size array can produce 0 as sum

        vector<vector<bool>> tab(n + 1, vector<bool>(sum + 1, false));

        for (int i = 0; i <= n; i++)
        {
            tab[i][0] = true;
        }

        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = 0; j <= sum; j++)
        //     {
        //         cout << tab[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                {
                    tab[i][j] = tab[i - 1][j - arr[i - 1]] || tab[i - 1][j];
                }
                else
                {
                    tab[i][j] = tab[i - 1][j];
                }
            }
        }

        return tab[n][sum];
    }
};