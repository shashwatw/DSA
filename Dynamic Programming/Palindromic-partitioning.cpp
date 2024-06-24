//* https://www.geeksforgeeks.org/problems/palindromic-patitioning4845/1
//* INTUITION
//^ We got to know that it is a problem of MCM because we needed to check for every combination for checking min partitions
//^ We identified i and j at 0 and N-1 posn as unlike MCM base ques we didnt needed val[i-1] therefore we took i as 0
//^ Now after it we computed base condition as i >= j then return 0 as a if i = j.. then single char that is a palindrome already so no need of any partitions
//^ Then we checked for partitioning scheme.... we did ran k from i to j-1 and made solve calls as wriiten solve(i to k) and solve(k+1, j);
//& Other scheme could be k = i+1 to j and solve(i to k-1) and solve(k to j) but we prefer prev scheme
//^ then we add a 1 in tempans i.e temp = solve(i to k) + solve(k+1 to j) + 1 (this 1 denotes partitioning between two partitions as we two pieces are getting done here 1 partition is made)
//^finally we return the min ans;

//* ------------------- RECURSIVE APPROACH ----------------------

class Solution
{
public:
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        return solve(str, 0, n - 1);
    }

    int solve(string str, int i, int j)
    {
        if (i >= j)
            return 0; // all single characters are palind...return 0 ie 0 partition

        if (isPalindrome(str, i, j))
            return 0;

        int minAns = INT_MAX;

        for (int k = i; k <= j - 1; k++)
        {
            int tempAns = solve(str, i, k) + solve(str, k + 1, j) + 1;

            minAns = min(minAns, tempAns);
        }
        return minAns;
    }

    bool isPalindrome(string str, int i, int j)
    {
        while (i < j)
        {
            if (str[i] != str[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

//* ------------------- RECURSIVE MEMOIZED APPROACH WITH OPTIMIZATIONS----------------------

class Solution
{
public:
    int dp[1001][1001];

    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        memset(dp, -1, sizeof(dp));
        return solve(str, 0, n - 1);
    }

    int solve(string &str, int i, int j)
    {
        if (i >= j)
            return 0; // all single characters are palind...return 0 ie 0 partition

        if (dp[i][j] != -1)
            return dp[i][j];

        if (isPalindrome(str, i, j))
            return 0;

        int minAns = INT_MAX;
        int l, r;
        for (int k = i; k <= j - 1; k++)
        {
            if (dp[i][k] != -1)
            {
                l = dp[i][k];
            }
            else
            {
                l = solve(str, i, k);
                dp[i][k] = l;
            }

            if (dp[k + 1][j] != -1)
            {
                r = dp[k + 1][j];
            }
            else
            {
                r = solve(str, k + 1, j);
                dp[k + 1][j] = r;
            }

            int tempAns = l + r + 1;

            minAns = min(minAns, tempAns);
        }
        return dp[i][j] = minAns;
    }

    bool isPalindrome(string &str, int i, int j)
    {
        while (i < j)
        {
            if (str[i] != str[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};