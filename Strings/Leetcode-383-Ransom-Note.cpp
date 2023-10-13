// https://leetcode.com/problems/ransom-note/description/

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        map<char, int> mpp;

        for (char c : magazine)
        {
            if (mpp.find(c) != mpp.end())
            {
                // If it's in the map, increment the count
                mpp[c]++;
            }
            else
            {
                // If it's not in the map, add it with a count of 1
                mpp[c] = 1;
            }
        }

        for (char t : ransomNote)
        {
            if (mpp.find(t) != mpp.end())
            {
                mpp[t]--;
                if (mpp[t] < 0)
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};