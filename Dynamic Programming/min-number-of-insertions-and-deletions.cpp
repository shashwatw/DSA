//* https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

//* Here we are checking lcs for both strings and we have divided the problem in two parts :
//^ 1. Making string 1 into LCS
//^ 2. Making LCS into string 2

//* heap ---- > pea
//*  |           |
//*  |           |
//*  |--> ea --> |

//* Here to make heap ---> ea  ... we did length(heap) - length(ea)  i.e. (4-2 = 2 deletions)
//* Now to make  ea   ---> pea ... we did length(ea)   - length(pea) i.e. (2-3 = 1 insertion)

class Solution
{

public:
    int minOperations(string str1, string str2)
    {
        // Your code goes here
        int m = str1.size();
        int n = str2.size();

        int lcs = computeLCS(str1, str2, m, n);

        int deletion = str1.size() - lcs;
        int insertion = str2.size() - lcs;

        return insertion + deletion;
    }

    int computeLCS(string str1, string str2, int m, int n)
    {
        vector<vector<int>> tab(m + 1, vector<int>(n + 1, 0));

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
        return tab[m][n];
    }
};