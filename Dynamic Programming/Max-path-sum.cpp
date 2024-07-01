//* https://www.geeksforgeeks.org/problems/path-in-matrix3805/1

//^ INTUITION
//* As we are in this question variable starting and ending points we have to start a loop to start from each cell of last row and having first row as our destination
//* STEPS
//* 1. Identify i and j
//* 2. Explore all paths (straight, left, right)
//* 3. Perform the function

//& ******************************************RECURSIVE*********************************************************
//~ TC - O(3^n) as 3 paths straight, left, right
//~ SC- O(n) at max we will travel n rows

class Solution
{
private:
    int solve(int i, int j, vector<vector<int>> &Matrix, int n)
    {
        if (j < 0 || j >= n)
            return -1e9; // Using n for both dimensions for a square matrix

        if (i == 0)
            return Matrix[0][j]; // Base case: return the value in the first row

        int s = Matrix[i][j] + solve(i - 1, j, Matrix, n);
        int left = Matrix[i][j] + solve(i - 1, j - 1, Matrix, n);
        int right = Matrix[i][j] + solve(i - 1, j + 1, Matrix, n);

        return max(s, max(left, right));
    }

public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // Initialize the maximum path sum to a very low value
        int maxPathSum = -1e9;

        // Compute the maximum path sum starting from the bottom row and all columns
        for (int j = 0; j < N; j++)
        {
            maxPathSum = max(maxPathSum, solve(N - 1, j, Matrix, N));
        }

        return maxPathSum;
    }
};

//& ******************************************MEMOIZATION*********************************************************
//~ TC - O(n*m)
//~ SC- O(n*m) + O(n)->recur stack space

class Solution
{
private:
    int solve(int i, int j, vector<vector<int>> &Matrix, int n, vector<vector<int>> &dp)
    {
        if (j < 0 || j >= n)
            return -1e9; // Using n for both dimensions for a square matrix

        if (i == 0)
            return Matrix[0][j]; // Base case: return the value in the first row

        if (dp[i][j] != -1)
            return dp[i][j];

        int straight = Matrix[i][j] + solve(i - 1, j, Matrix, n, dp);
        int left = Matrix[i][j] + solve(i - 1, j - 1, Matrix, n, dp);
        int right = Matrix[i][j] + solve(i - 1, j + 1, Matrix, n, dp);

        return dp[i][j] = max(straight, max(left, right));
    }

public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // Initialize the maximum path sum to a very low value
        int maxPathSum = -1e9;

        vector<vector<int>> dp(N, vector<int>(N, -1));

        // Compute the maximum path sum starting from the bottom row and all columns
        for (int j = 0; j < N; j++)
        {
            maxPathSum = max(maxPathSum, solve(N - 1, j, Matrix, N, dp));
        }

        return maxPathSum;
    }
};

//& ******************************************TABULATION (Bottom up)*********************************************************
//~ TC - O(n*m) + O(n)
//~ SC- O(n*m) and no recur stack space

class Solution
{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // Initialize the maximum path sum to a very low value
        int maxPathSum = -1e9;

        vector<vector<int>> dp(N, vector<int>(N, -1));

        // Filling base case
        for (int j = 0; j < N; j++)
        {
            dp[0][j] = Matrix[0][j];
        }

        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int up = Matrix[i][j] + dp[i - 1][j];

                int left = -1e9;
                if (j - 1 >= 0)
                {
                    left = Matrix[i][j] + dp[i - 1][j - 1];
                }

                int right = -1e9;
                if (j + 1 < N)
                {
                    right = Matrix[i][j] + dp[i - 1][j + 1];
                }

                dp[i][j] = max(up, max(left, right));
            }
        }

        // return largest path sum from last row
        int maxi = dp[N - 1][0];

        for (int j = 1; j < N; j++)
        {
            maxi = max(maxi, dp[N - 1][j]);
        }
        return maxi;
    }
};

//& ******************************************1D Space Optimized TABULATION (Bottom up)************************************

class Solution
{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // Initialize the maximum path sum to a very low value
        int maxPathSum = -1e9;

        vector<int> prev(N);

        // Filling base case
        for (int j = 0; j < N; j++)
        {
            prev[j] = Matrix[0][j];
        }

        for (int i = 1; i < N; i++)
        {
            vector<int> curr(N);
            for (int j = 0; j < N; j++)
            {
                int up = Matrix[i][j] + prev[j];

                int left = -1e9;
                if (j - 1 >= 0)
                {
                    left = Matrix[i][j] + prev[j - 1];
                }

                int right = -1e9;
                if (j + 1 < N)
                {
                    right = Matrix[i][j] + prev[j + 1];
                }

                curr[j] = max(up, max(left, right));
            }
            prev = curr;
        }

        // return largest path sum from last row
        int maxi = -1e9;

        for (int j = 0; j < N; j++)
        {
            maxi = max(maxi, prev[j]);
        }
        return maxi;
    }
};