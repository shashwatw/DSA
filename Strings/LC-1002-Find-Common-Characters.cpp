//* https://leetcode.com/problems/find-common-characters/

class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        // Step 1: Initialize the minimum frequency array to a large number
        vector<int> minFreq(26, INT_MAX);

        // Step 2: Process each word to update the minimum frequency array
        for (auto word : words)
        {
            vector<int> freq(26, 0);
            for (char ch : word)
            {
                freq[ch - 'a']++;
            }
            // Update the minimum frequency for each character
            for (int i = 0; i < 26; i++)
            {
                minFreq[i] = min(minFreq[i], freq[i]);
            }
        }

        // Step 3: Collect the common characters based on their minimum frequency
        vector<string> ans;
        for (int i = 0; i < 26; i++)
        {
            while (minFreq[i] > 0)
            {
                ans.push_back(string(1, 'a' + i));
                minFreq[i]--;
            }
        }

        return ans;
    }
};
