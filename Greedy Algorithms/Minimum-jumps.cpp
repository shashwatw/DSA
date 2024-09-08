//* https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

// Function to return minimum number of jumps to end of array

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        // Your code here

        int n = arr.size();

        if (n == 1)
            return 0;
        if (arr[0] == 0)
            return -1;

        int jumps = 0;
        int current_end = 0;
        int farthest = 0;

        for (int i = 0; i < n - 1; i++)
        {

            farthest = max(farthest, i + arr[i]);

            if (i == current_end)
            {
                jumps++;
                current_end = farthest;
            }
        }

        if (current_end >= n - 1)
        {
            return jumps;
        }

        return -1;
    }
};