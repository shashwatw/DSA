//^ https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1
//* APPROACH 1

// User function template for C++
class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> &arr)
    {
        // code here
        int row = arr.size();
        int col = arr[0].size();
        int maxOnes = 0;
        int ans = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (arr[i][j] == 1)
                {
                    if (maxOnes < col - j)
                    {
                        maxOnes = max(maxOnes, col - j);
                        ans = i;
                        break;
                    }
                }
            }
        }
        if (ans == 0 && maxOnes == 0)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};

//* BETTER TIME OPTIMIZED

//^ Optimized Approach
//* Start from Top Right: Start from the top-right corner of the matrix.
//* Move Left or Down:
//* If the current element is 1, move left to find more 1s in the same row.
//* If the current element is 0, move down to the next row.
//* Track the row with maximum 1s: Keep track of the row index that has the maximum number of 1s.

// User function template for C++
class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> &arr)
    {
        // code here
        int row = arr.size();
        int col = arr[0].size();
        int j = col - 1;
        int maxRow = -1;

        for (int i = 0; i < row; i++)
        {
            while (j >= 0 && arr[i][j] == 1)
            {
                j--;
                maxRow = i;
            }
        }
        return maxRow;
    }
};