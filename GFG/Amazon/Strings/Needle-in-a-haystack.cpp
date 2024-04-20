// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-strings/problem/needle-in-a-haystack

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
int NeedleinHaystack(string haystack, string needle);

// } Driver Code Ends
// User function Template for C++

int NeedleinHaystack(string haystack, string needle)
{
    // Your code goes here

    int i = 0;

    while (i < haystack.length())
    {
        string ans = haystack.substr(i, needle.length());

        if (ans == needle)
            return i;

        i++;
    }
    return -1;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string haystack, needle;
        getline(cin, haystack);
        getline(cin, needle);
        cout << NeedleinHaystack(haystack, needle) << "\n";
    }
    return 0;
}
// } Driver Code Ends