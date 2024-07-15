//* https://leetcode.com/problems/remove-k-digits/

//^ **************************************Better Approach************************************************************

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> st;
        for (char digit : num)
        {
            while (!st.empty() && k > 0 && st.top() > digit)
            {
                st.pop();
                k--;
            }
            st.push(digit);
        }

        // Remove remaining digits from the end if k > 0
        while (k > 0 && !st.empty())
        {
            st.pop();
            k--;
        }

        // Construct the result from the stack
        string res;
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        // Remove leading zeros
        int leadingZeroIndex = 0;
        while (leadingZeroIndex < res.size() && res[leadingZeroIndex] == '0')
        {
            leadingZeroIndex++;
        }

        res = res.substr(leadingZeroIndex);

        // If result is empty, return "0"
        return res.empty() ? "0" : res;
    }
};

//^ Another Approach

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        vector<char> stk;
        string ans;
        for (char c : num)
        {
            while (k > 0 && !stk.empty() && stk.back() > c)
            {
                stk.pop_back();
                k--;
            }
            stk.push_back(c);
        }
        while (k > 0)
        {
            stk.pop_back();
            k--;
        }
        for (char c : stk)
        {
            if (ans.empty() && c == '0')
                continue;
            ans.push_back(c);
        }
        return ans.empty() ? "0" : ans;
    }
};
