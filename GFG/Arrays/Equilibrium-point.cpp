// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/equilibrium-point-1587115620
//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int equilibriumPoint(long long a[], int n)
    {
        if (n == 1)
        {
            return a[0];
        }

        long long sum = 0;
        long long presum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += a[i];
        }

        for (int i = 0; i < n; i++)
        {
            sum -= a[i];

            if (presum == sum)
            {
                return i + 1;
            }

            presum += a[i];
        }

        return -1;
    }
};

//{ Driver Code Starts.

int main()
{

    long long t;

    // taking testcases
    cin >> t;

    while (t--)
    {
        long long n;

        // taking input n
        cin >> n;
        long long a[n];

        // adding elements to the array
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;

        // calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends