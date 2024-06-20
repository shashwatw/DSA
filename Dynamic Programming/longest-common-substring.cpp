//* https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

class Solution
{
public:
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        // your code here
        vector<vector<int>> tab(n + 1, vector<int>(m + 1, 0));
        int maxCount = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (S1[i - 1] == S2[j - 1])
                {
                    tab[i][j] = 1 + tab[i - 1][j - 1];
                    maxCount = max(tab[i][j], maxCount);
                }
                else
                {
                    tab[i][j] = 0;
                }
            }
        }
        return maxCount;
    }
};