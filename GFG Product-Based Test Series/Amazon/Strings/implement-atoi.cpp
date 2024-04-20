//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int atoi(string str)
    {
        int ans = 0;
        int sign = 1;
        int i = 0;

        while (str[i] == ' ')
            i++;

        if (str[i] == '-' || str[i] == '+')
        {
            sign = (str[i] == '-') ? -1 : 1;
            i++;
        }

        while (isdigit(str[i]))
        {
            int digit = str[i] - '0';

            // Check for overflow
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7))
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        while (i < str.size() && str[i] == ' ')
            i++;

        if (i < str.size())
            return -1;

        return ans * sign;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.atoi(s) << endl;
    }
}
// } Driver Code Ends