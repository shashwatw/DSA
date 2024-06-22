//* https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

//^ APPROACH
//* Everything same as LCS but we took d=both strings as same and also if the char are same at same index (that will always be if both strings are same) we should not take this into cinsideration of repeating sequence... Therefore we took i=this constraint that i != j ... check in line 21

class Solution
{
public:
    int LongestRepeatingSubsequence(string str)
    {
        // Code here
        string str2 = str;
        int m = str.size();

        vector<vector<int>> tab(m + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str[i - 1] == str2[j - 1] && i != j)
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