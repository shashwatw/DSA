//* https://leetcode.com/problems/powx-n/description/

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 0)
            return x;
        if (n == 0)
            return 1;

        if (n & 1) // returns true if n is odd(bitwise operation)
        {
            if (n > 0)
                return x * pow(myPow(x, n / 2), 2);
            else
                return (1 / x) * pow(myPow(x, n / 2), 2);
        }
        else
            return pow(myPow(x, n / 2), 2);
    }
};