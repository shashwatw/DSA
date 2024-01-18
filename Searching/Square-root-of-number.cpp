// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-searching/problem/square-root

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution
{
public:
    long long int floorSqrt(long long int x)
    {
        int l = 0;
        int h = x;
        long long int mid = 0;

        if (x > 10)
        {
            h = x / 2;
        }

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

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends