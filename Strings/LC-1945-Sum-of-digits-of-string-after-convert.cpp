//* https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/

class Solution
{
public:
    int getLucky(string s, int k)
    {
        int sum = 0;
        string temp = "";

        for (int i = 0; i < s.size(); i++)
        {
            int val = (int)s[i] - 96;
            temp.append(to_string(val));
        }

        while (k != 0)
        {
            sum = 0;
            for (auto it : temp)
            {
                int val = (int)it - '0';
                sum += val;
            }
            temp = to_string(sum);
            k--;
        }
        return sum;
    }
};