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