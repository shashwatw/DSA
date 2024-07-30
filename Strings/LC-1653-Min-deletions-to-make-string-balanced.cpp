//* https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/

class Solution
{
public:
    int minimumDeletions(string s)
    {
        int dp = 0;
        int count_b = 0;

        for (auto character : s)
        {
            if (character == 'a')
            {
                dp = min(dp + 1, count_b);
            }
            else
            {
                count_b++;
            }
        }
        return dp;
    }
};