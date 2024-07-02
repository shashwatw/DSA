//* https://leetcode.com/problems/edit-distance/description/
//& Reference : https://www.youtube.com/watch?v=fJaKO8FbDdo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=34

//^ ---------------------------------------------------RECURSIVE----------------------------------------------------------------

class Solution
{
private:
    int minDistanceHelper(string &word1, string &word2, int m, int n)
    {
        // Base cases
        if (m == 0)
            return n; // If word1 is empty, we need to insert all characters of
                      // word2
        if (n == 0)
            return m; // If word2 is empty, we need to delete all characters of
                      // word1

        // If last characters are the same, no operation is needed for the last
        // character
        if (word1[m - 1] == word2[n - 1])
            return minDistanceHelper(word1, word2, m - 1, n - 1);

        // If last characters are different, consider all possibilities and find
        // the minimum
        int insertOp = minDistanceHelper(word1, word2, m, n - 1);
        int deleteOp = minDistanceHelper(word1, word2, m - 1, n);
        int replaceOp = minDistanceHelper(word1, word2, m - 1, n - 1);

        return 1 + min(insertOp, min(deleteOp, replaceOp));
    }

public:
    int minDistance(string word1, string word2)
    {
        return minDistanceHelper(word1, word2, word1.size(), word2.size());
    }
};

//^ ---------------------------------------------------MEMOIZATION--------------------------------------------------------------

class Solution
{
private:
    int minDistanceHelper(string &word1, string &word2, int i, int j, vector<vector<int>> &dp)
    {
        // Base cases
        if (i == 0)
            return j; // If word1 is empty, we need to insert all characters of
                      // word2
        if (j == 0)
            return i; // If word2 is empty, we need to delete all characters of
                      // word1

        if (dp[i][j] != -1)
            return dp[i][j];

        // If last characters are the same, no operation is needed for the last
        // character
        if (word1[i - 1] == word2[j - 1])
            return dp[i][j] = minDistanceHelper(word1, word2, i - 1, j - 1, dp);

        // If last characters are different, consider all possibilities and find
        // the minimum
        int insertOp = minDistanceHelper(word1, word2, i, j - 1, dp);
        int deleteOp = minDistanceHelper(word1, word2, i - 1, j, dp);
        int replaceOp = minDistanceHelper(word1, word2, i - 1, j - 1, dp);

        return dp[i][j] = 1 + min(insertOp, min(deleteOp, replaceOp));
    }

public:
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        return minDistanceHelper(word1, word2, word1.size(), word2.size(), dp);
    }
};

//^ ---------------------------------------------------TABULATION----------------------------------------------------------------

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill the base cases
        for (int i = 0; i <= m; ++i)
        {
            dp[i][0] = i; // Deleting all characters from word1 to match an empty word2
        }
        for (int j = 0; j <= n; ++j)
        {
            dp[0][j] = j; // Inserting all characters of word2 into an empty word1
        }

        // Fill the DP table
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1]; // No operation needed if characters match
                }
                else
                {
                    dp[i][j] = min({
                        dp[i - 1][j] + 1,    // Deletion
                        dp[i][j - 1] + 1,    // Insertion
                        dp[i - 1][j - 1] + 1 // Substitution
                    });
                }
            }
        }

        return dp[m][n];
    }
};

//^ ---------------------------------------------------1D Space Optimized TABULATION---------------------------------------------

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();

        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        // Fill the base cases
        for (int j = 0; j <= n; j++)
        {
            prev[j] = j;
        }

        // Fill the DP table
        for (int i = 1; i <= m; ++i)
        {
            curr[0] = i;
            for (int j = 1; j <= n; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    // No operation needed if characters match
                    curr[j] = prev[j - 1];
                }
                else
                {
                    curr[j] = 1 + min(prev[j],
                                      min(             // Deletion
                                          curr[j - 1], // Insertion
                                          prev[j - 1]  // Substitution
                                          ));
                }
            }
            prev = curr;
        }

        return prev[n];
    }
};
