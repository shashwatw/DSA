//* https://www.geeksforgeeks.org/problems/remaining-string3515/1

// User function template for C++
class Solution
{
public:
    string printString(string s, char ch, int count)
    {
        // Your code goes here
        string res = "";
        int n = s.size() - 1;
        for (int i = 0; i < s.size(); i++)
        {
            if (count == 0)
            {
                res = s.substr(i, n);
                return res;
            }
            if (s[i] == ch)
            {
                count--;
            }
        }
        return "";
    }
};