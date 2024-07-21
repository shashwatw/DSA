//^ https://www.geeksforgeeks.org/problems/maximum-product-subset-of-an-array/1

// User function Template for C++
class Solution
{
public:
    long long int findMaxProduct(vector<int> &arr)
    {
        // Write your code here
        int n = arr.size();

        if (n == 1)
            return arr[0];

        long long MOD = 1e9 + 7;
        long long product = 1;
        int neg_count = 0;
        int max_neg = INT_MIN;
        int zero_count = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                zero_count++;
                continue;
            }

            if (arr[i] < 0)
            {
                neg_count++;
                max_neg = max(max_neg, arr[i]);
            }

            product = (product * arr[i]) % MOD;
        }

        if (neg_count % 2 == 1)
        {

            if ((neg_count == 1) && (zero_count > 0) && (neg_count + zero_count == n))
            {
                return 0;
            }

            product = (product / max_neg);
        }

        return product;
    }
};