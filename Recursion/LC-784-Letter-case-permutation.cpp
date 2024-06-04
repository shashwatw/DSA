//* https://leetcode.com/problems/letter-case-permutation/description/

//^https://www.youtube.com/watch?v=4eOPYDOiwFo&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=16

class Solution
{
public:
    void solve(string ip, string op, vector<string> &res)
    {
        if (ip.size() == 0)
        {
            res.push_back(op);
            return;
        }

        string op1 = op;
        string op2 = op;

        if (tolower(ip[0]) == toupper(ip[0]))
        {
            op1 += ip[0];
            ip.erase(ip.begin() + 0);

            solve(ip, op1, res);
        }
        else
        {
            op1 += tolower(ip[0]);
            op2 += toupper(ip[0]);

            ip.erase(ip.begin() + 0);

            solve(ip, op1, res);
            solve(ip, op2, res);
        }
    }

    vector<string> letterCasePermutation(string s)
    {
        int n = s.size() - 1;

        string ip = s;
        string op = "";

        vector<string> res;

        solve(ip, op, res);

        return res;
    }
};