class Solution
{

public:
    string print_longest_common_subsequences(string s, string t)
    {
        // Code here
        string res;

        int m = s.size();
        int n = t.size();
        vector<vector<int>> tab(m + 1, vector<int>(n + 1, 0));

        lcs(s, t, m, n, tab);

        int i = m;
        int j = n;

        while (i > 0 && j > 0)
        {
            if (s[i - 1] == t[i - 1])
            {
                res.push_back(s[i - 1]);
                i--;
                j--;
            }
            else
            {
                if (tab[i][j - 1] > tab[i - 1][j])
                {
                    j--;
                }
                else
                {
                    i--;
                }
            }
        }
        return res;
    }

    void lcs(string s, string t, int m, int n, vector<vector<int>> &tab)
    {
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    tab[i][j] = 1 + tab[i - 1][j - 1];
                }
                else
                {
                    tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
                }
            }
        }
    }
};