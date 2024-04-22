//! https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

class Solution
{
public:
    // Function to reverse words in a given string.
    string reverseWords(string S)
    {
        // code here
        string temp = "";
        string ans = "";

        for (int i = S.size() - 1; i >= 0; i--)
        {
            if (S[i] == '.')
            {
                reverse(temp.begin(), temp.end());
                ans = ans + temp;
                ans.push_back('.');
                temp = "";
            }
            else
            {
                temp += S[i];
            }
        }
        reverse(temp.begin(), temp.end());
        ans = ans + temp;

        return ans;
    }
};