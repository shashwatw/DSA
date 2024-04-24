//^ https://leetcode.com/problems/n-th-tribonacci-number/description/

class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;

        long long a = 0, b = 1, c = 1; // Use long long instead of int
        long long sum = 0;
        for (int i = 3; i <= n; i++)
        {
            sum = a + b + c;
            a = b;
            b = c;
            c = sum;
        }

        return sum;
    }
};
