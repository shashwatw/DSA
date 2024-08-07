//! https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        // code

        sort(a.begin(), a.end());

        int diff;
        int mini = INT_MAX;

        int i = 0;
        int j = m - 1;

        while (j < a.size())
        {
            diff = a[j] - a[i];

            mini = min(mini, diff);

            i++;
            j++;
        }

        return mini;
    }
};