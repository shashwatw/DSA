//*https://leetcode.com/problems/delete-operation-for-two-strings/description/

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();

        int lcs = computeLCS(word1, word2, m, n);

        int deletionsInWord1 = word1.size() - lcs;
        int deletionsInWord2 = word2.size() - lcs;

        int totalOperations = deletionsInWord1 + deletionsInWord2;

        return totalOperations;
    }

    int computeLCS(string word1, string word2, int m, int n)
    {
        vector<vector<int>> tab(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1])
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