//^ Length of longest common subsequence
//* https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

// function to find longest common subsequence

//*               APPROACH 1 ---- RECURSION

class Solution
{
public:
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string str1, string str2)
    {
        // your code here
        if (n == 0 || m == 0)
            return 0;

        if (str1[n - 1] == str2[m - 1])
        {
            return 1 + lcs(n - 1, m - 1, str1, str2);
        }
        else
        {
            return max(lcs(n - 1, m, str1, str2), lcs(n, m - 1, str1, str2));
        }
    }
};

//*               APPROACH 2 ---- MEMOIZATION

// function to find longest common subsequence

class Solution
{
public:
    int lcshelper(string str1, string str2, int n, int m, vector<vector<int>> &tab)
    {
        if (n == 0 || m == 0)
            return 0;

        if (tab[n][m] != -1)
        {
            return tab[n][m];
        }

        if (str1[n - 1] == str2[m - 1])
        {
            return tab[n][m] = 1 + lcshelper(str1, str2, n - 1, m - 1, tab);
        }
        else
        {
            return tab[n][m] = max(lcshelper(str1, str2, n - 1, m, tab), lcshelper(str1, str2, n, m - 1, tab));
        }
    }

    // Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string str1, string str2)
    {
        // your code here
        vector<vector<int>> tab(n + 1, vector<int>(m + 1, -1));

        // Call the helper function and return its result
        return lcshelper(str1, str2, n, m, tab);
    }
};