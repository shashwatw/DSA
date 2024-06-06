//* https://www.geeksforgeeks.org/problems/josephus-problem/1

//^https://www.youtube.com/watch?v=ULUNeD0N9yI&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=19

/*You are required to complete this method */

class Solution
{
private:
    void solve(vector<int> &v, int k, int index, int &ans)
    {
        if (v.size() == 1)
        {
            ans = v[0];
            return;
        }

        index = (index + k) % v.size();

        v.erase(v.begin() + index);

        solve(v, k, index, ans);
    }

public:
    int josephus(int n, int k)
    {
        // Your code here
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = i + 1;
        }

        k = k - 1; // 0 based indexing

        int index = 0; // starting of round
        int ans = -1;

        solve(v, k, index, ans);

        return ans;
    }
};
