//* https://www.geeksforgeeks.org/problems/help-nobita0532/1

class Solution
{
public:
    string oddEven(const string &s)
    {
        // Calculate the frequency of each character
        unordered_map<char, int> freq;
        for (char c : s)
        {
            freq[c]++;
        }

        int x = 0;
        int y = 0;

        // Check each character's frequency and position in the alphabet
        for (const auto &entry : freq)
        {
            char c = entry.first;
            int count = entry.second;
            int position = c - 'a' + 1; // Get the position of the character in the alphabet (1-based)

            if (position % 2 == 0 && count % 2 == 0)
            {
                // Even position and even frequency
                x++;
            }
            else if (position % 2 != 0 && count % 2 != 0)
            {
                // Odd position and odd frequency
                y++;
            }
        }

        // Determine if the sum of x and y is even or odd
        if ((x + y) % 2 == 0)
        {
            return "EVEN";
        }
        else
        {
            return "ODD";
        }
    }
};