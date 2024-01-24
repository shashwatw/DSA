// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-strings/problem/reverse-words-in-a-given-string5459

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to reverse words in a given string.
    string reverseWords(string S)
    {
        stack<string> st;
        string res = "";
        string str = "";

        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == '.')
            {
                st.push(str);
                str = "";
            }
            else
            {
                str += S[i];
            }
        }

        st.push(str);

        while (!st.empty())
        {
            if (res.size() == 0)
            {
                res += st.top();
                st.pop();
            }
            else
            {
                res += ".";
                res += st.top();
                st.pop();
            }
        }
        return res;
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
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends