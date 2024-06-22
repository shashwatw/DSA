//! LONGEST PALINDROMIC SUBSEQUENCE

//* https://www.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1

class Solution
{
public:
    int longestPalinSubseq(string A)
    {
        // code here
        string B = A;
        reverse(B.begin(), B.end());

        int m = A.size();

        vector<vector<int>> tab(m + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (A[i - 1] == B[j - 1])
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