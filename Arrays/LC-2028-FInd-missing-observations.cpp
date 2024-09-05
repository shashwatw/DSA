//* https://leetcode.com/problems/find-missing-observations/description

class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int sz = rolls.size();
        int rhs = (sz + n) * mean;
        int sum = 0;
        vector<int> res;

        for (auto it : rolls)
        {
            sum += it;
        }

        int lhs = rhs - sum;

        if (lhs < n || lhs > 6 * n)
        {
            return {};
        }

        int quotient = lhs / n;
        int remainder = lhs % n;

        for (int i = 0; i < n; i++)
        {
            if (remainder != 0)
            {
                res.push_back(quotient + 1);
                remainder--;
            }
            else
            {
                res.push_back(quotient);
            }
        }

        return res;
    }
};
