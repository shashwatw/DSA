//* https://www.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1

//^ INTUITION
//* Intially we want min attempts to reach threshhold floor
//* So we will approach it through MCM approach
//* We will identigy i and j as e and f
//* We will now check for base condns
//* 1. If the floor is 0 or 1 then min attempts would be f itself
//* 2. Id=f egg was only 1 then we have worst attempts as we can't afford to break the egg so we will move from down to up till egg gets broken.. as soon as it gets broken we return the attempts
//* Now we will be checking K loop
//* We will start it from k = 1 to f
//* Now here we want tempans to consist of worst case possible for the attempts so we will be taking max value
//* And finally we need min attempt as ans so we will update minAns variable accordingly
//* Finally we will return min attempts

//& -----------------------RECURSIVE APPROACH -------------------------------------------

class Solution
{
private:
    int solve(int e, int f)
    {
        if (f == 0 || f == 1)
            return f;
        if (e == 1)
            return f;

        int minAns = INT_MAX;

        for (int k = 1; k <= f; k++)
        {
            int tempAns = 1 + max(solve(e - 1, k - 1), solve(e, f - k));
            minAns = min(minAns, tempAns);
        }
        return minAns;
    }

public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int n, int k)
    {
        // your code here
        // n -> (nums of eggs)
        // k -> (num of floors)
        return solve(n, k);
    }
};

//& -----------------------MEMOIZED APPROACH -------------------------------------------

class Solution
{
    int memo[201][201];

private:
    int solve(int e, int f)
    {
        if (f == 0 || f == 1)
            return f;
        if (e == 1)
            return f;

        if (memo[e][f] != -1)
            return memo[e][f];

        int minAns = INT_MAX;

        for (int k = 1; k <= f; k++)
        {
            int breakEgg, noBreakEgg;
            if (memo[e - 1][k - 1] != -1)
            {
                breakEgg = memo[e - 1][k - 1];
            }
            else
            {
                breakEgg = solve(e - 1, k - 1);
                memo[e - 1][k - 1] = breakEgg;
            }

            if (memo[e][f - k] != -1)
            {
                noBreakEgg = memo[e][f - k];
            }
            else
            {
                noBreakEgg = solve(e, f - k);
                memo[e][f - k] = noBreakEgg;
            }

            int tempAns = 1 + max(breakEgg, noBreakEgg);
            minAns = min(minAns, tempAns);
        }
        return memo[e][f] = minAns;
    }

public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int n, int k)
    {
        // your code here
        // n -> (nums of eggs)
        // k -> (num of floors)
        memset(memo, -1, sizeof(memo));
        return solve(n, k);
    }
};