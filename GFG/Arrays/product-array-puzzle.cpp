// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/product-array-puzzle4525
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index

    vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
    {
        vector<long long int> sm(n, 1);
        vector<long long int> lg(n, 1);
        vector<long long int> res;

        long long int sum1 = 1;
        long long int sum2 = 1;

        for (int i = 1; i < n; i++)
        {
            sum1 *= nums[i - 1];
            sm[i] = sum1;
        }

        for (int i = n - 2; i >= 0; i--)
        {
            sum2 *= nums[i + 1];
            lg[i] = sum2;
        }

        for (int i = 0; i < n; i++)
        {
            res.push_back(sm[i] * lg[i]);
        }

        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; // number of test cases
    cin >> t;
    while (t--)
    {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr, n); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends