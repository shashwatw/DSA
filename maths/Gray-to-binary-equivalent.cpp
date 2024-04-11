// https://www.geeksforgeeks.org/problems/gray-to-binary-equivalent-1587115620/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        int binary = 0;
        // Start with the most significant bit (MSB)
        while (n != 0)
        {
            // XOR each bit with the previously processed bit
            binary ^= n;
            // Right shift the Gray code to process the next bit
            n >>= 1;
        }
        return binary;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t, n;
    cin >> t; // testcases
    while (t--)
    {
        cin >> n; // initializing n

        Solution ob;
        // calling function grayToBinary()
        cout << ob.grayToBinary(n) << endl;
    }
}

// } Driver Code Ends