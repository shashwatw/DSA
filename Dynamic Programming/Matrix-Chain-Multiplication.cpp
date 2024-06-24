//* https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

//^ Reference Video: https://www.youtube.com/watch?v=kMK148J9qEE&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=35

//* ------------------RECURSIVE APPROACH-----------------------
//^ Here we broke the question into pieces
//^ 1. Identifying i and j
//^ 2. Identifying Base Condition
//^ 3. Checking the for loop to run k
//^ 4. Writing solve function
//^ 5. Deriving formula of num of multiplications of the two broken matrices
// User function Template for C++

class Solution
{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        return solve(arr, 1, N - 1);
    }

    int solve(int arr[], int i, int j)
    {
        if (i >= j)
            return 0;

        int min = INT_MAX;

        for (int k = i; k <= j - 1; k++)
        {
            int tempans = solve(arr, i, k) + solve(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);

            if (tempans < min)
            {
                min = tempans;
            }
        }
        return min;
    }
};

//* ------------------MEMOIZATION APPROACH-----------------------
//^ 1. We will first check the constraints of size of matrix from the qiestion and take +1 more and make a 2D vector table[][] initialised with -1 in it
//^ 2. Now we will check table[][] that if val is not -1 then it may have changed by func so we will return the value directly through it
//^ 3. Else we will move to compute and finally while returning store in table[][] for future use

class Solution
{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        // initialise size according to constraints of N...here N is >= 100
        // therefore took 101 X 101
        vector<vector<int>> dp(101, vector<int>(101, -1));
        return solve(arr, 1, N - 1, dp);
    }

    int solve(int arr[], int i, int j, vector<vector<int>> &dp)
    {
        if (i >= j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int min = INT_MAX;

        for (int k = i; k <= j - 1; k++)
        {
            int tempans = solve(arr, i, k, dp) + solve(arr, k + 1, j, dp) + (arr[i - 1] * arr[k] * arr[j]);

            if (tempans < min)
            {
                min = tempans;
            }
        }
        return dp[i][j] = min;
    }
};