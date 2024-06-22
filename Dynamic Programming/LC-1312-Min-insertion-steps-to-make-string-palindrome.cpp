//* https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

//^ Here number of insertions will be equivalent to number of deletions as to get palindrome we will have some single elements and we can either delete those or insert those.

//^ There fore we will write code for number of deletions here as number of insertions will be same as number of deletions

class Solution
{
public:
    int minInsertions(string s)
    {
        // return s.size() - LPS
        int m = s.size();
        string t = s;

        reverse(t.begin(), t.end());

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

        int numDeletions = m - tab[m][m];
        return numDeletions;
    }
};