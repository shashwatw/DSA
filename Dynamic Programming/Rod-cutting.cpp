//* https://www.geeksforgeeks.org/problems/rod-cutting0840/1

class Solution
{
public:
    int cutRod(int price[], int n)
    {
        // code here
        vector<int> length(n);
        int cnt = 1;

        for (int i = 0; i < n; i++)
        {
            length[i] = cnt;
            cnt++;
        }

        vector<vector<int>> tab(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (length[i - 1] <= j)
                {
                    tab[i][j] = max(price[i - 1] + tab[i][j - length[i - 1]], tab[i - 1][j]);
                }
                else
                {
                    tab[i][j] = tab[i - 1][j];
                }
            }
        }

        return tab[n][n];
    }
};