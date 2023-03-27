class Solution
{
public:
    long long int mySqrt(int x)
    {
        long long int l, h, mid;
        long long int ans = -1;
        l = 0;
        h = x;
        mid = (l + h) / 2;

        while (l <= h)
        {
            mid = (l + h) / 2;
            if (mid * mid < x)
            {
                l = mid + 1;
                ans = mid;
            }
            else if (mid * mid == x)
            {
                return (mid);
            }
            else
            {
                h = mid - 1;
            }
        }
        return (ans);
    }
};