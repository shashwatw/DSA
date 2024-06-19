//* https://www.codechef.com/learn/course/dynamic-programming/LIDPDSA06/problems/CNTWAYC

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int countWaysToCutRibbon(int N, int L)
{
    // If L < 2, there are no even lengths possible, return 0
    if (L < 2)
        return 0;

    // Initialize the dp array
    vector<int> dp(N + 1, 0);
    dp[0] = 1; // There's one way to have a ribbon of length 0 (no cuts)

    // Fill the dp array
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 2; j <= min(L, i); j += 2)
        { // Only consider even lengths j <= L
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }

    return dp[N];
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, L;
        cin >> N >> L;
        cout << countWaysToCutRibbon(N, L) << endl;
    }

    return 0;
}
