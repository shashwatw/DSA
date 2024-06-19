//^ Length of longest common subsequence
//* https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

// function to find longest common subsequence

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
