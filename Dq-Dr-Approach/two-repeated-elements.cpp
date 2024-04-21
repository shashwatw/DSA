// https://www.geeksforgeeks.org/problems/two-repeated-elements-1587115621/1

class Solution
{
public:
    // Function to find two repeated elements.
    vector<int> twoRepeated(int arr[], int n)
    {
        // Your code here
        // D = d*q + r
        // x = d*q
        // r = remainder

        int x = n + 1;
        vector<int> res;

        for (int i = 0; i < n + 2; i++)
        {
            int r = arr[i] % x;

            if (arr[r] / x > 0)
            {
                res.push_back(r);
            }
            arr[r] += x;
        }
        return res;
    }
};