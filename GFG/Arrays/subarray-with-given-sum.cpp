// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/subarray-with-given-sum-1587115621
class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s)
    {
        // Your code here
        vector<int> res;

        int i = 0, j = 1;
        long long sum = arr[0];

        while (j < n)
        {

            while (j < n && sum < s)
            {
                sum = sum + arr[j++];
            }

            while (i < j && sum > s)
            {
                sum = sum - arr[i++];
            }

            if (sum == 0 && i < j)
                j++;
            if (sum == s && i < j)
            {
                res.push_back(i + 1);
                res.push_back(j);
                return res;
            }
            else if (sum == s)
            {
                res.push_back(-1);
                return res;
            }
        }

        if (sum == s)
        {
            res.push_back(i + 1);
            res.push_back(j);
            return res;
        }

        if (res.size() == 0)
            res.push_back(-1);

        return res;
    }
};