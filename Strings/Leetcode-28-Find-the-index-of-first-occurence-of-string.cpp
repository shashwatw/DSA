// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int h_len = haystack.length();
        int n_len = needle.length();

        // If the needle is an empty string, return 0
        if (n_len == 0)
        {
            return 0;
        }

        // Iterate through the haystack string
        for (int i = 0; i <= h_len - n_len; ++i)
        {
            // Check if the substring of haystack matches the needle
            if (haystack.substr(i, n_len) == needle)
            {
                return i; // Found a match, return the index
            }
        }

        // If no match is found, return -1
        return -1;
    }
};
