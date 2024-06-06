//* https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/
//! JOSEPHUS PROBLEM
//^https://www.youtube.com/watch?v=ULUNeD0N9yI&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=19

class Solution
{
private:
    void solve(int k, int index, int &ans, vector<int> &v)
    {
        if (v.size() == 1)
        {
            ans = v[0];
            return;
        }

        index = (index + k) % v.size();

        v.erase(v.begin() + index);

        solve(k, index, ans, v);
    }

public:
    int findTheWinner(int n, int k)
    {
        vector<int> v(n);

        for (int i = 0; i < n; i++)
        {
            v[i] = i + 1;
        }

        k = k - 1; // 0 based indexing

        int index = 0; // starting of counting
        int ans = -1;

        solve(k, index, ans, v);

        return ans;
    }
};