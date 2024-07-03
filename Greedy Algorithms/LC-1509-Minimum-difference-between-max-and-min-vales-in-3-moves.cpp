//* https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves

class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        int numsSize = nums.size();

        // If the array has 4 or fewer elements, return 0
        if (numsSize <= 4)
            return 0;

        sort(nums.begin(), nums.end());

        int minDiff = INT_MAX;

        // possible optimal scenarios:
        //     Removing the three largest elements.
        //     Removing the two largest and one smallest elements.
        //     Removing one largest and two smallest elements.
        //     Removing the three smallest elements.

        // Four scenarios to compute the minimum difference
        for (int left = 0, right = numsSize - 4; left < 4; left++, right++)
        {
            minDiff = min(minDiff, nums[right] - nums[left]);
        }

        return minDiff;
    }
};