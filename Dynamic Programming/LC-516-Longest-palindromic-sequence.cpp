//* https://leetcode.com/problems/longest-palindromic-subsequence/

//^ INTUITION :
//* We just had one string so we have to think of second string for computing lcs... as palindromic sequence would only be left we took LCS of s and reverse string s... therefore we came to conclusion that second string is nothing but reversed initial string
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        int m = s.size();

        vector<vector<int>> tab(m + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= m; j++)
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
        return tab[m][m];
    }
};