// https://www.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        // max(a,b) <= c
        // a+b > c
        int ans = 0;
        sort(arr, arr + n);

        for (int i = n - 1; i >= 2; i--)
        {
            int l = 0;
            int h = i - 1;

            while (l < h)
            {
                if (arr[l] + arr[h] > arr[i])
                {
                    ans += (h - l);
                    h--;
                }
                else
                {
                    l++;
                }
            }
        }
        return ans;
    }
};

// 7 -> 764
// 8 -> 876 874 864
// 9 -> 987 986 984 976 974 964
// 10 -> 1098 1097 1096 1094 1087 1086 1084 1076 1074 "1064"

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.findNumberOfTriangles(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends