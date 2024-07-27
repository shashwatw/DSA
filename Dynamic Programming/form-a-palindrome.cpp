//^ https://www.geeksforgeeks.org/problems/form-a-palindrome1455/1

// User function template for C++

class Solution
{
private:
    int computeLCS(string &str1, string &str2, int n, int m, vector<vector<int>> &dp)
    {
        if (n == 0 || m == 0)
        {
            return 0;
        }

        if (dp[n][m] != -1)
        {
            return dp[n][m];
        }

        if (str1[n - 1] == str2[m - 1])
        {
            dp[n][m] = 1 + computeLCS(str1, str2, n - 1, m - 1, dp);
        }
        else
        {
            dp[n][m] = max(computeLCS(str1, str2, n - 1, m, dp), computeLCS(str1, str2, n, m - 1, dp));
        }
        return dp[n][m];
    }

public:
    int countMin(string str)
    {
        // complete the function here
        int n = str.size();
        string str2 = str;
        reverse(str2.begin(), str2.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        int lcs = computeLCS(str, str2, n, n, dp);

        return n - lcs;
    }
};