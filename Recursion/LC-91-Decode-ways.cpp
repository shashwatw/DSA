//* class Solution {
private:
int solve(string &s, int cnt1, int cnt2, int ind)
{
    if (ind == s.size())
        return cnt1 + cnt2;

    int new_cnt1 = 0, new_cnt2 = 0;
    char curr = s[ind];
    char prev;

    if (ind > 0)
    {
        prev = s[ind - 1];
    }
    else
    {
        prev = 0;
    }

    if (curr != '0')
    {
        new_cnt1 = cnt1 + cnt2;
    }

    if (ind > 0)
    {
        int two_digit = (prev - '0') * 10 + (curr - '0');
        if (two_digit >= 10 && two_digit <= 26)
        {
            new_cnt2 = cnt1;
        }
    }

    return solve(s, new_cnt1, new_cnt2, ind + 1);
}

public:
int numDecodings(string s)
{
    if (s.empty() || s[0] == '0')
        return 0;
    return solve(s, 1, 0, 1);
}
}
;

class Solution
{
private:
    int solve(string &s, int cnt1, int cnt2, int ind)
    {
        if (ind == s.size())
            return cnt1 + cnt2;

        int new_cnt1 = 0, new_cnt2 = 0;
        char curr = s[ind];
        char prev;

        if (ind > 0)
        {
            prev = s[ind - 1];
        }
        else
        {
            prev = 0;
        }

        if (curr != '0')
        {
            new_cnt1 = cnt1 + cnt2;
        }

        if (ind > 0)
        {
            int two_digit = (prev - '0') * 10 + (curr - '0');
            if (two_digit >= 10 && two_digit <= 26)
            {
                new_cnt2 = cnt1;
            }
        }

        return solve(s, new_cnt1, new_cnt2, ind + 1);
    }

public:
    int numDecodings(string s)
    {
        if (s.empty() || s[0] == '0')
            return 0;
        return solve(s, 1, 0, 1);
    }
};
