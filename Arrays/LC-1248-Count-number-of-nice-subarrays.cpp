//* https://leetcode.com/problems/count-number-of-nice-subarrays/description/

class Solution
{
public:
    int numberOfSubarrays(std::vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> odds;

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] % 2 != 0)
            {
                odds.push_back(i);
            }
        }

        if (odds.size() < k)
        {
            return 0;
        }

        int count = 0;

        for (int i = 0; i <= odds.size() - k; ++i)
        {
            int start = odds[i];
            int end = odds[i + k - 1]; // end of win pe

            int zerosBefore;
            if (i == 0)
            {
                zerosBefore = start;
            }
            else
            {
                zerosBefore = start - odds[i - 1] - 1;
            }

            // last odd ke baad num count
            int zerosAfter;
            if (i + k - 1 == odds.size() - 1)
            {
                zerosAfter = n - end - 1;
            }
            else
            {
                zerosAfter = odds[i + k] - end - 1;
            }

            count += (zerosBefore + 1) * (zerosAfter + 1);
        }

        return count;
    }
};