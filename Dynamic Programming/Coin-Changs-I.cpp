//* https://www.geeksforgeeks.org/problems/coin-change2448/1
//^ Maximum number of ways you can make sum by using different combinations from coins[ ].

class Solution
{
public:
    long long int count(int coins[], int n, int sum)
    {

        // code here.
        vector<vector<long long>> tab(n + 1, vector<long long>(sum + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            tab[i][0] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (coins[i - 1] <= j)
                {
                    tab[i][j] = tab[i][j - coins[i - 1]] + tab[i - 1][j];
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