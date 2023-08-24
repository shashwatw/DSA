//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n - 1;

        while (l < h) {
            int mid = l + (h - l) / 2;

            if (nums[mid] < nums[h]) {
                // Right half is sorted, the minimum must be in the left half
                h = mid;
            } else {
                // Left half is sorted, the minimum must be in the right half
                l = mid + 1;
            }
        }

        return nums[l]; // Minimum element found
    }
};
