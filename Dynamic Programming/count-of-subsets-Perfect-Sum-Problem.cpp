//*https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
//^ Reference : https://www.youtube.com/watch?v=F7wqWbqYn9g&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=9

//! SAME LOGIC AS EQUAL PARTITION SUBSET SUM JUST INSTEAD || USED + TO GET COUNT OF SUBSETS

class Solution
{

public:
    int perfectSum(int arr[], int n, int sum)
    {
        // Your code goes here
        vector<vector<int>> tab(n + 1, vector<int>(sum + 1, 0));

        long long MOD = 1e9 + 7;

        for (int i = 0; i <= n; i++)
        {
            tab[i][0] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                {
                    tab[i][j] = tab[i - 1][j - arr[i - 1]] % MOD + tab[i - 1][j] % MOD;
                }
                else
                {
                    tab[i][j] = tab[i - 1][j];
                }
            }
        }
        return tab[n][sum] % MOD;
    }
};
