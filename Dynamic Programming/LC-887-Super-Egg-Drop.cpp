//* https://leetcode.com/problems/super-egg-drop/description/

class Solution
{
    int memo[101][10001];

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
        int low = 0, high = f;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int eggBreak, noEggBreak;
            if (memo[e - 1][mid - 1] != -1)
            {
                eggBreak = memo[e - 1][mid - 1];
            }
            else
            {
                eggBreak = solve(e - 1, mid - 1);
                memo[e - 1][mid - 1] = eggBreak;
            }

            if (memo[e][f - mid] != -1)
            {
                noEggBreak = memo[e][f - mid];
            }
            else
            {
                noEggBreak = solve(e, f - mid);
                memo[e][f - mid] = noEggBreak;
            }

            int tempAns = 1 + max(eggBreak, noEggBreak);

            if (eggBreak > noEggBreak)
            {
                high = mid - 1;
            }
            else
                low = mid + 1;

            minAns = min(minAns, tempAns);
        }
        return memo[e][f] = minAns;
    }

public:
    int superEggDrop(int k, int n)
    {
        memset(memo, -1, sizeof(memo));
        return solve(k, n);
    }
};