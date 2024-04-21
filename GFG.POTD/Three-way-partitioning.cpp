// https://www.geeksforgeeks.org/problems/three-way-partitioning/1

// User function template for C++

class Solution
{
public:
    // Function to partition the array around the range such
    // that array is divided into three parts.
    void threeWayPartition(vector<int> &array, int a, int b)
    {
        int l = 0;
        int n = array.size();
        int h = n - 1;

        for (int i = 0; i <= h; i++)
        {
            if (array[i] < a)
            {
                swap(array[i], array[l]);
                l++;
            }
            else if (array[i] > b)
            {
                swap(array[i], array[h]);
                h--;
                i--;
            }
        }
    }
};