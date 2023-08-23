//https://www.codingninjas.com/studio/problems/valid-parentheses_795104?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <stack>
#include <string>

bool isValidParenthesis(std::string s) {
    std::stack<char> st;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        } else {
            if (st.empty()) return false;

            char c = st.top();
            st.pop();
            if ((s[i] == ')' && c == '(') || (s[i] == ']' && c == '[') || (s[i] == '}' && c == '{')) {
                continue;
            } else {
                return false;
            }
        }
    }

    return st.empty();
}
