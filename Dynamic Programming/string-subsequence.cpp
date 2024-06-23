//* https://www.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence3020/1

class Solution
{
public:
    int countWays(string s1, string s2)
    {
        // code here
        int m = s1.size();
        int n = s2.size();
        int MOD = 1e9 + 7;

        vector<vector<int>> tab(m + 1, vector<int>(n + 1, 0));

        // initialise first row with 1
        for (int i = 0; i <= m; i++)
        {
            tab[i][0] = 1;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    tab[i][j] = tab[i - 1][j - 1] % MOD + tab[i - 1][j] % MOD;
                }
                else
                {
                    tab[i][j] = tab[i - 1][j];
                }
            }
        }
        return tab[m][n] % MOD;
    }
};