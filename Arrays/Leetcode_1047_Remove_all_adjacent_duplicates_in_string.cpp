class Solution
{
public:
    string removeDuplicates(string str)
    {

        int n = str.size();

        stack<char> st;

        for (int i = 0; i < n; i++)
        {
            bool flag = true;

            if (st.empty() == false && st.top() == str[i])
            {
                flag = false;

                st.pop();
            }

            if (flag)
            {
                st.push(str[i]);
            }
        }

        string res = "";

        while (!st.empty())
        {
            res += st.top();

            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};