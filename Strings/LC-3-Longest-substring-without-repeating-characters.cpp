//* https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int cnt = 0;                 // Store the maximum length of a valid substring found so far
        int temp = 0;                // Store the length of the current substring being evaluated
        unordered_map<char, int> mp; // Map to store the last seen index of each character

        int start = 0; // Start index of the current substring

        for (int i = 0; i < s.size(); i++)
        {
            if (mp.find(s[i]) == mp.end() || mp[s[i]] < start)
            {
                mp[s[i]] = i; // Update the last seen index of s[i]
                temp++;
            }
            else
            {
                cnt = max(cnt, temp); // Update the maximum length if necessary
                start = mp[s[i]] + 1; // Move the start to one past the last occurrence of s[i]
                temp = i - start + 1; // Calculate the new length of the substring
                mp[s[i]] = i;         // Update the last seen index of s[i]
            }
        }

        cnt = max(cnt, temp); // Final check to update the maximum length
        return cnt;
    }
};
