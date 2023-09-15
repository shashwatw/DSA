// https://leetcode.com/problems/length-of-last-word/description/

class Solution
{
public:
    int lengthOfLastWord(string s)
    {

        int count = 0;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                count++;
            }
            else
            {
                if (count == 0)
                {
                    continue;
                }
                else
                {
                    return count;
                }
            }
        }
        return count;
    }
};