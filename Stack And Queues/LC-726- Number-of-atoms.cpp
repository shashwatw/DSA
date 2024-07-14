//* https://leetcode.com/problems/number-of-atoms/description

class Solution
{
public:
    string countOfAtoms(string formula)
    {
        map<string, int> mp;
        stack<int> stk;
        int mf = 1; // multiplicity or mult factor
        int n = formula.size();
        int last = 1;

        for (int i = n - 1; i >= 0;)
        {
            // Untill we are encountering number
            if (isdigit(formula[i]))
            {
                int end = i;
                int st = end;
                // to check all numbers before it
                while (st >= 0 && isdigit(formula[st]))
                    st--;
                // converting string of all numbers in int
                int num = stoi(formula.substr(st + 1, end - st));
                i = st;

                // storing the number or multiplicity if in case its jst predecessor is atom
                last = num;
            }
            else if (formula[i] == '(')
            {
                // If we encounter open bracket means one set of bracket is completed
                // So multiply atom's freq with stack's top frequency
                mf /= stk.top();
                stk.pop();
                i--;
            }
            else if (formula[i] == ')')
            {
                // Push the last multiplicity we got into the stack
                mf *= last;
                stk.push(last);
                last = 1;
                i--;
            }
            else
            {
                // If we get small letter...it is not complete elem name
                // Traverse till we get capital letter
                int end = i;
                int st = end;
                while (st >= 0 && islower(formula[st]))
                    st--;
                string atom = formula.substr(st, end - st + 1);
                i = st - 1;
                mp[atom] += last * mf;
                last = 1;
            }
        }

        string res;
        for (const auto &x : mp)
        {
            res += x.first;
            if (x.second > 1)
                res += to_string(x.second);
        }

        return res;
    }
};