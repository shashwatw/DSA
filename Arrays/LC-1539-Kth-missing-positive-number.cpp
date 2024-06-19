//* https://leetcode.com/problems/kth-missing-positive-number/description/

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int i = 1, j = 0, k1 = 0;
        while (j < n)
        {
            int curr = arr[j];

            if (i == curr)
            {
                i++;
                j++;
            }
            else
            {
                k1++;
                if (k1 == k)
                    return i;
                else
                    i++;
            }
        }
        return i + (k - k1 - 1);
    }
};