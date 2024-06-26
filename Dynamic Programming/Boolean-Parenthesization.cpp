//* https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1

// User function Template for C++

//^ ---=====------======----=====----RECURSIVE CODE-----======-----========-------======

class Solution
{
private:
    int solve(string s, int i, int j, bool isTrue)
    {
        // base condition
        if (i > j)
        {
            return false; // automatically handles false and returns 0 ( instead false )
        }
        if (i == j)
        {
            if (isTrue == true)
            {
                return s[i] == 'T';
            }
            else
            {
                return s[i] == 'F';
            }
        }

        int ans = 0;
        for (int k = i + 1; k <= j - 1; k += 2)
        {
            int lT = solve(s, i, k - 1, true);  // left true
            int lF = solve(s, i, k - 1, false); // left false
            int rT = solve(s, k + 1, j, true);  // right true
            int rF = solve(s, k + 1, j, false); // right false

            // now we will check for each operator (&, |, ^)
            if (s[k] == '&')
            {
                if (isTrue == true)
                {
                    ans += (lT * rT); // both should be true
                }
                else
                {
                    ans += (lF * rT) + (lT * rF) + (lF * rF); // any one / both should be false
                }
            }
            else if (s[k] == '|')
            {
                if (isTrue == true)
                {
                    ans += (lT * rT) + (lT * rF) + (lF * rT); // any one should be true
                }
                else
                {
                    ans += (lF * rF); // both should be false
                }
            }
            else if (s[k] == '^')
            {
                if (isTrue == true)
                {
                    ans += (lT * rF) + (lF * rT); // xor condition
                }
                else
                {
                    ans += (lT * rT) + (lF * rF);
                }
            }
        }
        return ans;
    }

public:
    int countWays(int n, string s)
    {
        // code here
        bool isTrue;
        return solve(s, 0, n - 1, true);
    }
};