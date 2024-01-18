// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-searching/problem/find-transition-point-1587115620

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int transitionPoint(int arr[], int n)
    {
        int l = 0;
        int h = n - 1;
        int mid = 0;

        while (l <= h)
        {
            mid = l + (h - l) / 2;

            if (arr[mid] == 1)
            {
                if (arr[mid] == arr[mid - 1])
                {
                    h = mid - 1;
                }
                else
                {
                    return mid;
                }
            }
            else if (arr[mid] == 0)
            {
                l = mid + 1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int transitionPoint(int arr[], int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends