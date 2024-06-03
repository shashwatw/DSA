//* https://www.geeksforgeeks.org/problems/trail-of-ones3242/1

#define MOD 1000000007
class Solution
{
public:
    int numberOfConsecutiveOnes(int n)
    {
        // code here

        // The series is 0, 1, 3, 8, 19, 43, 94 ...
        // n = 2: 2 * 0  + 1 = 1
        // n = 3: 2 * 1  + 1 = 3
        // n = 4: 2 * 3  + 2 = 8
        // n = 5: 2 * 8  + 3 = 19
        // n = 6: 2 * 19 + 5 = 43
        // n = 7: 2 * 43 + 8 = 92

        vector<int> dp(1e5 + 2, 0);
        dp[2] = 1;

        int a = 0;
        int b = 1;

        for (int i = 3; i <= n; i++)
        {
            int sum = (a + b) % MOD;
            dp[i] = ((dp[i - 1] * 2) % MOD + sum) % MOD;
            a = b;
            b = sum;
        }
        return dp[n] % MOD;
    }
};