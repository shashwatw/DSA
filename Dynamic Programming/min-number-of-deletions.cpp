//* https://www.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1

int minDeletions(string str, int n)
{
    // complete the function here
    string str2 = str;
    reverse(str2.begin(), str2.end());

    vector<vector<int>> tab(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str[i - 1] == str2[j - 1])
            {
                tab[i][j] = 1 + tab[i - 1][j - 1];
            }
            else
            {
                tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
            }
        }
    }

    int lps = tab[n][n];

    int deletions = n - lps;

    return deletions;
}