//! https://www.geeksforgeeks.org/problems/rohans-love-for-matrix4723/1
// User function Template for C++
class Solution
{
public:
    int firstElement(int n)
    {
        // code here
        // fibonacci seq found

        if (n == 1 || n == 2)
            return 1;

        int a = 1;
        int b = 1;
        int res = 0;

        for (int i = 2; i < n; i++)
        {
            res = (a + b) % 1000000007;
            a = b;
            b = res;
        }
        return res;
    }
};