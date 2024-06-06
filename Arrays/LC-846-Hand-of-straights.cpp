//* https://leetcode.com/problems/hand-of-straights/description/

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        map<int, int> count;

        for (auto card : hand)
        {
            count[card]++;
        }

        for (auto [start, _] : count)
        {
            int val = count[start];
            if (val > 0)
            {
                for (int i = start; i < start + groupSize; i++)
                {
                    count[i] = count[i] - val;
                    if (count[i] < 0)
                        return false;
                }
            }
        }
        return true;
    }
};