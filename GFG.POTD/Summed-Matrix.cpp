//* https://www.geeksforgeeks.org/problems/summed-matrix5834/1

//^ TC and SC - O(N)

class Solution
{
public:
    long long sumMatrix(long long n, long long q)
    {
        // code here
        if (2 * n >= q)
        {
            return n - abs(n + 1 - q);
        }
        else
        {
            return 0;
        }
    }
};