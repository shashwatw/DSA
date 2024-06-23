//* https://www.geeksforgeeks.org/problems/find-length-of-longest-subsequence4905/1

int maxSubsequenceSubstring(string X, string Y, int N, int M)
{
    // code
    vector<vector<int>> tab(N + 1, vector<int>(M + 1, 0));
    int ans = INT_MIN;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                tab[i][j] = 1 + tab[i - 1][j - 1];
            }
            else
            {
                tab[i][j] = tab[i - 1][j];
            }
            ans = max(ans, tab[i][j]);
        }
    }
    return ans;
}
