//* https://www.geeksforgeeks.org/problems/square-root/1

// Function to find square root
// x: element to find square root
class Solution
{
public:
    long long int floorSqrt(long long int x)
    {
        if (x == 1)
            return 1;
        int l = 0;
        int h = x / 2;
        long long int mid = 0;

        while (l <= h)
        {
            mid = l + (h - l) / 2;
            if (mid * mid > x)
            {
                h = mid - 1;
            }
            else if (mid * mid < x)
            {
                l = mid + 1;
            }
            else if (mid * mid == x)
            {
                return mid;
            }
        }
        return h;
    }
};