//* https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/

//* Check freq of most occ and allocate it with first posn in numpad
//* Then as we can accomodate starting 8 greater freq ones in first posn
//* Others will be placed at 2nd posn so will multiply by 2
//* then at 3rd posn and finally 4th

class Solution
{
public:
    int minimumPushes(string word)
    {
        unordered_map<char, int> mp;
        vector<int> freq;
        int cnt = 0, moves = 0;

        for (char it : word)
        {
            mp[it]++;
        }

        for (auto it : mp)
        {
            freq.push_back(it.second);
        }
        sort(freq.begin(), freq.end(), greater<int>());

        for (int i = 0; i < freq.size(); i++)
        {
            cnt++;
            if (cnt <= 8)
            {
                moves += freq[i] * 1;
            }
            else if (cnt <= 16)
            {
                moves += freq[i] * 2;
            }
            else if (cnt <= 24)
            {
                moves += freq[i] * 3;
            }
            else
            {
                moves += freq[i] * 4;
            }
        }
        return moves;
    }
};