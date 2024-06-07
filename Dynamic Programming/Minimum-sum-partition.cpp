//* https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1
//^ Reference Video : https://www.youtube.com/watch?v=-GtpxG6l_Mc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=10

class Solution
{

public:
    int minDifference(int arr[], int n)
    {
        //* Your code goes here
        int range = 0; // total sum

        for (int i = 0; i < n; i++)
        {
            range += arr[i];
        }
        //* subset sum logic
        vector<vector<bool>> tab(n + 1, vector<bool>(range + 1, false));

        for (int i = 0; i <= n; i++)
        {
            tab[i][0] = true;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= range; j++)
            {
                if (arr[i - 1] <= j)
                {
                    tab[i][j] = tab[i - 1][j - arr[i - 1]] || tab[i - 1][j];
                }
                else
                {
                    tab[i][j] = tab[i - 1][j];
                }
            }
        }

        //* Here instead of storing till range/2 the last rows indexes which got true
        //* I directly used it from the tab
        int min_diff = INT_MAX;
        for (int i = 0; i <= range / 2; i++)
        {
            if (tab[n][i])
            {
                min_diff = min(min_diff, range - 2 * i);
            }
        }

        return min_diff;
    }
};