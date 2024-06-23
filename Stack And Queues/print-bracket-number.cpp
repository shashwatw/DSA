//* https://www.geeksforgeeks.org/problems/print-bracket-number4058/1

// User function template for C++
class Solution
{
public:
    vector<int> bracketNumbers(string str)
    {
        // Your code goes here
        stack<int> st;
        vector<int> res;
        int num = 0;

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(')
            {
                num++;
                st.push(num);
                res.push_back(num);
            }
            else if (str[i] == ')')
            {
                int topel = st.top();
                res.push_back(topel);
                st.pop();
            }
            else
            {
                continue;
            }
        }
        return res;
    }
};