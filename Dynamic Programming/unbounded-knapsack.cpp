//* https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
class Solution
{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> tab(N + 1, vector<int>(W + 1, 0));

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                if (wt[i - 1] <= j)
                {
                    //^ The index below i is the only diff between 01 knapsakc and unbounded
                    //^ Here just don't change index if taken the val of it as we can take again here
                    //*                              i
                    tab[i][j] = max(val[i - 1] + tab[i][j - wt[i - 1]], tab[i - 1][j]);
                }
                else
                {
                    tab[i][j] = tab[i - 1][j];
                }
            }
        }
        return tab[N][W];
    }
};