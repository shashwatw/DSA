//* https://www.geeksforgeeks.org/problems/make-matrix-beautiful-1587115620/1

class Solution
{
public:
    // Function to find minimum number of operations that are required
    // to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int>> matrix, int n)
    {
        // code here
        vector<long long> rowSum(n, 0);
        vector<long long> colSum(n, 0);
        int minOps = 0;

        long long maxSum = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int val = matrix[i][j];

                rowSum[i] += val;
                colSum[j] += val;

                maxSum = max(maxSum, rowSum[i]);
                maxSum = max(maxSum, colSum[j]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (rowSum[i] == maxSum)
                continue;
            else
            {
                for (int j = 0; j < n; j++)
                {
                    if (colSum[j] == maxSum)
                        continue;
                    else
                    {
                        int canBeAdded = min(maxSum - colSum[j], maxSum - rowSum[i]);
                        rowSum[i] += canBeAdded;
                        colSum[j] += canBeAdded;
                        minOps += canBeAdded;
                    }
                }
            }
        }

        return minOps;
    }
};