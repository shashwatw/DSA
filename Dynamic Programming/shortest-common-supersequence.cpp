//* https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1
//^ Reference Video : https://www.youtube.com/watch?v=823Grn4_dCQ&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=24

class Solution
{
public:
    // Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        // code here
        vector<vector<int>> tab(m + 1, vector<int>(n + 1, 0));
        int lcs = computeLCS(X, Y, m, n, tab);

        return ((m + n) - lcs);
    }

    int computeLCS(string X, string Y, int m, int n, vector<vector<int>> &tab)
    {

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (X[i - 1] == Y[j - 1])
                {
                    tab[i][j] = 1 + tab[i - 1][j - 1];
                }
                else
                {
                    tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
                }
            }
        }
        return tab[m][n];
    }
};