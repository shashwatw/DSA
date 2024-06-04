//* https://leetcode.com/problems/longest-palindrome/description/

class Solution
{
public:
    int longestPalindrome(string s)
    {
        // if all even -> size
        // if 1 odd n even -> size n + 1
        // n odd m even = size - n + 1

        if (s.size() == 1 || s.size() == 0)
            return s.size();

        unordered_map<char, int> mpp;

        int OddCnt = 0;

        for (auto it : s)
        {
            mpp[it]++;
        }

        for (auto it : mpp)
        {
            if (it.second % 2 == 1)
            {
                OddCnt++;
            }
        }

        if (OddCnt == 0)
        {
            return s.size();
        }
        else
        {
            return s.size() - OddCnt + 1;
        }
    }
};