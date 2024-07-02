//* https://www.geeksforgeeks.org/problems/edit-distance3702/1

class Solution
{
public:
    int editDistance(string s, string t)
    {
        // Code here
        int m = s.size();
        int n = t.size();

        vector<vector<int>> tab(m + 1, vector<int>(n + 1, 0));

        // base cases
        for (int i = 0; i <= m; i++)
        {
            tab[i][0] = i;
        }

        for (int j = 0; j <= n; j++)
        {
            tab[0][j] = j;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    tab[i][j] = tab[i - 1][j - 1];
                }
                else
                {
                    tab[i][j] = 1 + min(tab[i - 1][j], min(tab[i - 1][j - 1], tab[i][j - 1]));
                }
            }
        }
        return tab[m][n];
    }
};