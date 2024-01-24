// https://geeksforgeeks.org/batch/test-series-bundle/track/amazon-strings/problem/implement-strstr

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int strstr(string, string);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        string b;

        cin >> a;
        cin >> b;

        cout << strstr(a, b) << endl;
    }
}

// } Driver Code Ends

// Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
    int i = 0;
    int j = 0;

    while (i < s.size())
    {
        if (s[i] == x[j])
        {
            int temp_i = i;
            while (temp_i < s.size() && j < x.size() && s[temp_i] == x[j])
            {
                temp_i++;
                j++;
            }

            if (j == x.size())
            {
                return i;
            }
            else
            {
                j = 0;
            }

            i++;
        }
        else
        {
            i++;
        }
    }
    return -1;
}