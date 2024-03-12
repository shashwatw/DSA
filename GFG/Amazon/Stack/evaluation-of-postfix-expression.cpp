// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-stacks/problem/evaluation-of-postfix-expression1735

//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;

        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] != '+' && S[i] != '*' && S[i] != '/' && S[i] != '-')
            {
                st.push(S[i] - '0');
            }
            else
            {
                int n2 = st.top();
                st.pop();
                int n1 = st.top();
                st.pop();

                if (S[i] == '+')
                {
                    int calc = n1 + n2;
                    st.push(calc);
                }
                else if (S[i] == '*')
                {
                    int calc = n1 * n2;
                    st.push(calc);
                }
                else if (S[i] == '/')
                {
                    int calc = n1 / n2;
                    st.push(calc);
                }
                else
                {
                    int calc = n1 - n2;
                    st.push(calc);
                }
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--)
    {
        string S;
        cin >> S;
        Solution obj;

        cout << obj.evaluatePostfix(S) << endl;
    }
    return 0;
}

// } Driver Code Ends