//* https://www.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1

class Solution
{
public:
    // arr: input array
    // num: size of array
    // Function to find maximum circular subarray sum.

    int kadane(int arr[], int n)
    {
        int currSum = arr[0];
        int maxSum = arr[0];

        for (int i = 1; i < n; i++)
        {
            maxSum = max(maxSum + arr[i], arr[i]);
            currSum = max(maxSum, currSum);
        }
        return currSum;
    }

    int circularSubarraySum(int arr[], int n)
    {

        // your code here
        int max_normal_sum = kadane(arr, n);

        if (max_normal_sum < 0)
            return max_normal_sum;

        int arr_sum = 0;

        for (int i = 0; i < n; i++)
        {
            arr_sum += arr[i];
            arr[i] = -arr[i];
        }

        int max_neg_sum = kadane(arr, n);

        int max_circular_sum = arr_sum + max_neg_sum;

        return max(max_circular_sum, max_normal_sum);
    }
};