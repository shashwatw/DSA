//* https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
//& REference Video : https://www.youtube.com/watch?v=y4vN0WNdrlg&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=47

//^ INTUITION
//* Basically what we did was calculated increasing subsequence (LIS) till each index from front and stored in dp1[]
//* Similarly stored LIS from backward in dp2
//* Now we added all the same index ones as they will be bitonic if arranged and deducted 1 for the common element at index
//* Lastly we returned the maximum length we got as result

//^ NOT SOLUTION TO GITHUB PROBLEM AS IN THIS :
//! A strictly increasing or a strictly decreasing sequence is considered as a bitonic sequence
//^ but github problem told us that A strictly increasing or a strictly decreasing sequence should not be considered as a bitonic sequence -------> GITHUB SOLUTION AFTER THE BEOW SOLUTION

class Solution
{
public:
    int LongestBitonicSequence(int n, vector<int> &nums)
    {
        // code here

        vector<int> dp1(n, 1), dp2(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[i] > nums[prev] && dp1[prev] + 1 > dp1[i])
                {
                    dp1[i] = dp1[prev] + 1;
                }
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int prev = n - 1; prev > i; prev--)
            {
                if (nums[i] > nums[prev] && dp2[prev] + 1 > dp2[i])
                {
                    dp2[i] = dp2[prev] + 1;
                }
            }
        }

        int bitonic_length = 0;
        for (int i = 0; i < n; i++)
        {
            bitonic_length = max(bitonic_length, dp1[i] + dp2[i] - 1);
        }

        return bitonic_length;
    }
};

//^ A strictly increasing or a strictly decreasing sequence should not be considered as a bitonic sequence

class Solution
{
public:
    int LongestBitonicSequence(int n, vector<int> &nums)
    {
        // code here
        if (n < 3)
            return 0;

        vector<int> dp1(n, 1), dp2(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[i] > nums[prev] && dp1[prev] + 1 > dp1[i])
                {
                    dp1[i] = dp1[prev] + 1;
                }
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int prev = n - 1; prev > i; prev--)
            {
                if (nums[i] > nums[prev] && dp2[prev] + 1 > dp2[i])
                {
                    dp2[i] = dp2[prev] + 1;
                }
            }
        }

        int bitonic_length = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp1[i] > 1 && dp2[i] > 1)
            {
                // Ensure there's an increasing and a decreasing part
                bitonic_length = max(bitonic_length, dp1[i] + dp2[i] - 1);
            }
        }

        return bitonic_length;
    }
};