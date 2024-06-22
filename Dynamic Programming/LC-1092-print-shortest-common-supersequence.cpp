//* https://leetcode.com/problems/shortest-common-supersequence/description/

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int m = str1.size();
        int n = str2.size();

        string res;

        vector<vector<int>> tab(m + 1, vector<int>(n + 1, 0));

        lcs(str1, str2, m, n, tab);

        int i = m;
        int j = n;

        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                res.push_back(str1[i - 1]);
                i--;
                j--;
            }
            else
            {
                if (tab[i][j - 1] > tab[i - 1][j])
                {
                    res.push_back(str2[j - 1]);
                    j--;
                }
                else
                {
                    res.push_back(str1[i - 1]);
                    i--;
                }
            }
        }

        while (i > 0)
        {
            res.push_back(str1[i - 1]);
            i--;
        }

        while (j > 0)
        {
            res.push_back(str2[j - 1]);
            j--;
        }

        reverse(res.begin(), res.end());

        return res;
    }

    void lcs(string str1, string str2, int m, int n, vector<vector<int>> &tab)
    {
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1])
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