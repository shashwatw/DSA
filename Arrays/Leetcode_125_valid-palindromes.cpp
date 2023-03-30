#include <bits/stdc++.h>
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string temp = "";
        for (int i = 0; i < s.length(); i++)
        {
            if ((int(s[i]) >= 65 && int(s[i]) <= 90) || (int(s[i]) >= 97 && int(s[i]) <= 122) ||
                (int(s[i]) >= 48 && int(s[i]) <= 57))
                temp.push_back(tolower(s[i]));
        }
        cout << temp;
        int start = 0;
        int end = temp.length() - 1;
        while (start <= end)
        {
            if (temp[start] != temp[end])
            {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }
};