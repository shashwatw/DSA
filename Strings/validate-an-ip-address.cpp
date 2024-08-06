//* https://www.geeksforgeeks.org/problems/validate-an-ip-address-1587115621/1

// User function Template for C++
class Solution
{
public:
    int isValid(string str)
    {
        // code here
        int cnt = 0;
        string temp = "";

        for (auto it : str)
        {
            if (it == '.')
            {
                cnt++;
            }
        }

        if (cnt != 3)
            return 0;

        unordered_set<string> st;

        for (int i = 0; i <= 255; i++)
        {
            st.insert(to_string(i));
        }

        cnt = 0;

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != '.')
            {
                temp += str[i];
            }
            else
            {
                if (st.find(temp) != st.end())
                {
                    cnt++;
                    temp = "";
                }
            }
        }

        if (st.find(temp) != st.end())
        {
            cnt++;
        }

        if (cnt != 4)
        {
            return 0;
        }

        return 1;
    }
};