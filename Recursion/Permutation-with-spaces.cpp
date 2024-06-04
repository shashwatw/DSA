//* https://www.geeksforgeeks.org/problems/permutation-with-spaces3627/1
//^ Reference Video :https://www.youtube.com/watch?v=1cspuQ6qHW0&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=14
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

        op1 += " ";
        op1 += ip[0];

        op2 += ip[0];

        ip.erase(ip.begin() + 0);

        solve(ip, op1, res);
        solve(ip, op2, res);
    }

    vector<string> permutation(string s)
    {
        // Code Here
        string ip = s;
        string op = "";
        vector<string> res;

        op.push_back(ip[0]);
        ip.erase(ip.begin() + 0);

        solve(ip, op, res);

        return res;
    }
};
