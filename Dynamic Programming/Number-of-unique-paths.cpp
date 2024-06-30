//* https://www.geeksforgeeks.org/problems/number-of-unique-paths5339/0

// User function template in C++

class Solution
{
public:
    // Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        // code here
        vector<vector<int>> tab(a, vector<int>(b, 1));

        for (int i = 1; i < a; i++)
        {
            for (int j = 1; j < b; j++)
            {
                tab[i][j] = tab[i - 1][j] + tab[i][j - 1];
            }
        }
        return tab[a - 1][b - 1];
    }
};