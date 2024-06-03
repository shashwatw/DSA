//* https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/

class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int j = 0;
        int i = 0;
        while (i < s.size() && j < t.size())
        {
            if (s[i] == t[j])
            {
                j++;
            }
            i++;
        }

        return t.size() - j;
    }
};