//* https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1
//^ Reference Video : https://www.youtube.com/watch?v=U81n0UYtk98&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=18

// User function template for C++
class Solution
{
private:
    void solve(int one, int zero, string op, vector<string> &res, int n)
    {
        if (n == 0)
        {
            res.push_back(op);
            return;
        }

        string op1 = op;
        op1.push_back('1');
        solve(one + 1, zero, op1, res, n - 1);

        if (one > zero)
        {
            string op2 = op;
            op2.push_back('0');
            solve(one, zero + 1, op2, res, n - 1);
        }
    }

public:
    vector<string> NBitBinary(int n)
    {
        // Your code goes here
        vector<string> res;

        int one = 0;
        int zero = 0;

        string op = "";

        solve(one, zero, op, res, n);

        return res;
    }
};