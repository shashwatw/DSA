//* https://www.geeksforgeeks.org/problems/number-of-coins1824/1

class Solution
{

public:
    int minCoins(vector<int> &coins, int M, int V)
    {
        // Your code goes here
        vector<vector<int>> tab(M + 1, vector<int>(V + 1, 0));

        for (int i = 0; i <= V; i++)
        {
            tab[0][i] = INT_MAX - 1;
        }

        for (int i = 1; i <= M; i++)
        {
            for (int j = 1; j <= V; j++)
            {
                if (coins[i - 1] <= j)
                {
                    tab[i][j] = min(1 + tab[i][j - coins[i - 1]], tab[i - 1][j]);
                }
                else
                {
                    tab[i][j] = tab[i - 1][j];
                }
            }
        }
        return tab[M][V] == INT_MAX - 1 ? -1 : tab[M][V];
    }
};