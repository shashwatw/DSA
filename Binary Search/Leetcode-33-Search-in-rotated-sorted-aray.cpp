//https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int h = n - 1;
        int mid = 0;

        while (l <= h) {
            mid = l + (h - l) / 2;
            if (target == nums[mid]) {
                return mid; // Target found
            }
            if (nums[l] <= nums[mid]) {
                // Left part is sorted
                if (nums[l] <= target && target < nums[mid]) {
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                // Right part is sorted
                if (nums[mid] < target && target <= nums[h]) {
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            }
        }
        return -1; // Target not found
    }
};


