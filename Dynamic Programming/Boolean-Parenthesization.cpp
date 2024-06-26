//* https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1

// User function Template for C++

//* INTUITION

//* Initially we will find i and j that will be easy to find as 0, n-1
//* Find Base condns as if we want true and single element is present we will return true else false and vice versa
//* if i exceeds j i.e. i > j then we would return false
//* Now we will check for k loop
//* We know every 2nd char is operator so we wilmove k with 2 hops i.e. k += 2
//* Now we will break into 2 parts as i to k-1 and k+1 to j as k will be on operator so its index i.e s[k] will be operator
//* Now we will find every combination for each diff operator to compute true for which we need all partitions ways of true and false
//* Finally we will add the needed ways to obtain true as per various operations
//* We use 3D dp here because s remaining const.... i, j and isTrue variables are changing and check their size by constrains
//* 3D dp[1001][1001][2] // 2 for isTrue as it can hold either true or false

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

//* -------------------------MAP Approach (MEMOIZED)------- (not optimal)

// User function Template for C++

// ---=====------======----=====----MEMOIZED CODE-----======-----========-------======

class Solution
{
    unordered_map<string, int> mp;

private:
    int solve(string &s, int i, int j, bool isTrue)
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

        string temp = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);

        if (mp.find(temp) != mp.end())
        {
            return mp[temp];
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
                    ans += (lF * rT) + (lT * rF) + (lF * rF) % 1003; // any one / both should be false
                }
            }
            else if (s[k] == '|')
            {
                if (isTrue == true)
                {
                    ans += (lT * rT) + (lT * rF) + (lF * rT) % 1003; // any one should be true
                }
                else
                {
                    ans += (lF * rF) % 1003; // both should be false
                }
            }
            else if (s[k] == '^')
            {
                if (isTrue == true)
                {
                    ans += (lT * rF) + (lF * rT) % 1003; // xor condition
                }
                else
                {
                    ans += (lT * rT) + (lF * rF) % 1003;
                }
            }
        }
        return mp[temp] = ans % 1003;
    }

public:
    int countWays(int n, string s)
    {
        // code here
        bool isTrue;
        return solve(s, 0, n - 1, true);
    }
};

//* -------------------------3D DP Approach (MEMOIZED)------- (Optimal)

// User function Template for C++

// ---=====------======----=====----MEMOIZED CODE-----======-----========-------======

class Solution
{
    int dp[1001][1001][2];

private:
    int solve(string &s, int i, int j, bool isTrue)
    {
        // base condition
        if (dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];

        if (i > j)                       // invalid i/p
            return dp[i][j][isTrue] = 0; // false

        if (i == j) // smallest valid i/p
        {
            if (isTrue == true)
            {
                if (s[i] == 'T')                 // i& j index pointer always lies either on T or F
                    return dp[i][j][isTrue] = 1; // 1 -- > True
                else
                    return dp[i][j][isTrue] = 0; // 0 -- > False
            }
            else if (isTrue == false)
            {
                if (s[i] == 'F')
                    return dp[i][j][isTrue] = 1;
                else
                    return dp[i][j][isTrue] = 0;
            }
        }

        int ans = 0;
        for (int k = i + 1; k <= j - 1; k += 2)
        {
            int lT, lF, rT, rF;
            if (dp[i][k - 1][true] != -1) // lT -- > Left True
            {
                lT = dp[i][k - 1][true];
            }
            else
            {
                lT = solve(s, i, k - 1, true);
                dp[i][k - 1][true] = lT;
            }

            if (dp[i][k - 1][false] != -1) // lF -- > Left False
            {
                lF = dp[i][k - 1][false];
            }
            else
            {
                lF = solve(s, i, k - 1, false);
                dp[i][k - 1][false] = lF;
            }

            if (dp[k + 1][j][true] != -1) // rT -- > Right True
            {
                rT = dp[k + 1][j][true];
            }
            else
            {
                rT = solve(s, k + 1, j, true);
                dp[k + 1][j][true] = rT;
            }

            if (dp[k + 1][j][false] != -1) // rF -- > Right False
            {
                rF = dp[k + 1][j][false];
            }
            else
            {
                rF = solve(s, k + 1, j, false);
                dp[k + 1][j][false] = rF;
            }

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
                    ans += (lT * rT) + (lT * rF) + (lF * rT) % 1003; // any one should be true
                }
                else
                {
                    ans += (lF * rF) % 1003; // both should be false
                }
            }
            else if (s[k] == '^')
            {
                if (isTrue == true)
                {
                    ans += (lT * rF) + (lF * rT) % 1003; // xor condition
                }
                else
                {
                    ans += (lT * rT) + (lF * rF) % 1003;
                }
            }
        }
        return dp[i][j][isTrue] = ans % 1003;
    }

public:
    int countWays(int n, string s)
    {
        // code here
        memset(dp, -1, sizeof(dp));
        bool isTrue;
        return solve(s, 0, n - 1, true);
    }
};