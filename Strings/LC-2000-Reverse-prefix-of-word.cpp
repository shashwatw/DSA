//^ https://leetcode.com/problems/reverse-prefix-of-word/description/

class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        string ans = "";
        string temp = "";
        int cnt = 0;

        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] != ch)
            {
                temp += word[i];
            }
            else if (cnt == 0)
            {
                cnt++;
                temp += word[i];
                reverse(temp.begin(), temp.end());
                ans = ans + temp;
                temp = "";
            }
            else
            {
                temp += word[i];
            }
        }

        if (temp.size() != 0)
        {
            ans = ans + temp;
        }
        return ans;
    }
};
