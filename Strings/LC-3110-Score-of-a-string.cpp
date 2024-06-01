//* https://leetcode.com/problems/score-of-a-string/description/?envType=daily-question&envId=2024-06-01

class Solution
{
public:
    int scoreOfString(string s)
    {
        int score = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            int a = s[i] - 'a';
            int b = s[i + 1] - 'a';

            int a1 = a;
            int b1 = b;

            // cout << a1 << " " << b1 << endl;

            int differ = abs(abs(a) - abs(b));

            score += differ;
        }
        return score;
    }
};