//^ https://www.geeksforgeeks.org/problems/maximum-sum-of-hour-glass3842/1

//* Here initially if n or m will be less than 3 then hourglass shape is not possible
//* Now we assume for each cell to be leftmost element of hourglass and then took out the sum.
//* checked for max sum and returned the ans;

// User function Template for C++

class Solution
{
public:
    int findMaxSum(int n, int m, vector<vector<int>> mat)
    {
        // code here

        int res = INT_MIN;

        if (n < 3 || m < 3)
            return -1;

        for (int i = 0; i <= n - 3; i++)
        {
            for (int j = 0; j <= m - 3; j++)
            {
                int sum = 0;
                sum += mat[i][j] + mat[i][j + 1] + mat[i][j + 2] + mat[i + 1][j + 1] + mat[i + 2][j] + mat[i + 2][j + 1] + mat[i + 2][j + 2];

                res = max(res, sum);
            }
        }

        return res;
    }
};