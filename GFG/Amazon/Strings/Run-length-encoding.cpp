// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-strings/problem/run-length-encoding

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        string str;
        cin >> str;

        cout << encode(str) << endl;
    }
    return 0;
}
// } Driver Code Ends

/*You are required to complete this function */

string encode(string src)
{
    int cnt = 1; // Start with 1 to account for the first character
    char str = src[0];
    string ans = "";

    for (int i = 1; i < src.size(); i++)
    {
        if (str == src[i])
        {
            cnt++;
        }
        else
        {
            ans += str + to_string(cnt); // Concatenate character and count to the result string
            cnt = 1;                     // Reset count for the new character
            str = src[i];
        }
    }

    // Handle the last character and its count
    ans += str + to_string(cnt);

    return ans;
}
