//* https://leetcode.com/problems/unique-paths/

//^ INTUITION
//* We want to count unique paths
//* Now we know from any place in matrix we want to go to [0][0] place that is from destination we can only move left and up
//* So we consider once going up and once going left and finally sumup the answer
//* We wrote Base conditions as if it is start node then it is a path and if i or j is going out of matrix do not count as path

//^ -----------------------------------------RECURSIVE-------------------------------------------------

class Solution
{
private:
    int solve(int i, int j)
    {
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;

        int up = solve(i - 1, j);
        int left = solve(i, j - 1);

        return up + left;
    }

public:
    int uniquePaths(int m, int n)
    {

        return solve(m - 1, n - 1);
    }
};