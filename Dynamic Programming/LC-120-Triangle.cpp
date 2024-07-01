//* https://leetcode.com/problems/triangle/

//& INTUITION
//^ Here we want to find the min cost to reach last row but here ending points are variable... therefore can't start from end as if we do we will need to consider each point of last row
//^ Instead of that we preferred starting from fixed starting node
//^ We calculated both options and sum that what would be sum if we go down or diagonally
//^ Finally we return the min of both the cost

//* -----------------------------------------------RECURSIVE-----------------------------------------------------

class Solution
{
private:
    int solve(int i, int j, vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        if (i == n - 1)
            return triangle[i][j];

        int down = triangle[i][j] + solve(i + 1, j, triangle);
        int diagonally = triangle[i][j] + solve(i + 1, j + 1, triangle);

        return min(down, diagonally);
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        return solve(0, 0, triangle);
    }
};

//* -----------------------------------------------MEMOIZED-----------------------------------------------------

class Solution
{
private:
    int solve(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        int n = triangle.size();
        if (i == n - 1)
            return triangle[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = triangle[i][j] + solve(i + 1, j, triangle, dp);
        int diagonally = triangle[i][j] + solve(i + 1, j + 1, triangle, dp);

        return dp[i][j] = min(down, diagonally);
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, triangle, dp);
    }
};

//* -----------------------------------------------TABULATION-----------------------------------------------------

//^ Here we are running reverse of loop unlike traditional tab as we are starting from 0, 0
//^ In this case if starting points are reversed the tabulation works the reversed way
class Solution
{
private:
    int solve(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &tab)
    {
        int n = triangle.size();

        // base case
        for (int j = 0; j < n; j++)
        {
            tab[n - 1][j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + tab[i + 1][j];
                int diag = triangle[i][j] + tab[i + 1][j + 1];

                tab[i][j] = min(down, diag);
            }
        }
        return tab[0][0];
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> tab(n, vector<int>(n, 0));
        return solve(0, 0, triangle, tab);
    }
};

//* -----------------------------------------------1D Space optimized TABULATION-------------------------------------------------

class Solution
{
private:
    int solve(int i, int j, vector<vector<int>> &triangle)
    {
        int n = triangle.size();

        vector<int> front(n);

        // base case
        for (int j = 0; j < n; j++)
        {
            front[j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            vector<int> curr(n);
            for (int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + front[j];
                int diag = triangle[i][j] + front[j + 1];

                curr[j] = min(down, diag);
            }
            front = curr;
        }
        return front[0];
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        return solve(0, 0, triangle);
    }
};