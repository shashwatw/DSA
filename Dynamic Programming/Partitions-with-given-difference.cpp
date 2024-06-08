//* https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

class Solution
{
public:
    int countPartitions(int n, int d, vector<int> &arr)
    {
        //* Code here
        //* S1 - S2 = diff ------ (1)
        //* S1 + S2 = sum --------(2)
        //* (1) + (2)
        //* 2S1 = sum + diff
        //* S1 = (sum + diff)/2

        //* problem reduced to subset sum problem of finding subset of sum S1
        long long MOD = 1e9 + 7;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        if ((sum + d) % 2 != 0)
            return 0; //* if odd can't split in two halves

        int range = (sum + d) / 2;

        vector<vector<int>> tab(n + 1, vector<int>(range + 1, 0));

        tab[0][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= range; j++)
            {
                if (arr[i - 1] <= j)
                {
                    tab[i][j] = (tab[i - 1][j - arr[i - 1]] + tab[i - 1][j]) % MOD;
                }
                else
                {
                    tab[i][j] = tab[i - 1][j];
                }
            }
        }

        return tab[n][range];
    }
};