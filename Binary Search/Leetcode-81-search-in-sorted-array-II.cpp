//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int h = n - 1;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (nums[mid] == target) {
                return true; // Target found
            }

            if (nums[l] == nums[mid] && nums[mid] == nums[h]) {
                // Handling duplicates, move the pointers inward
                l++;
                h--;
            } else if (nums[l] <= nums[mid]) {
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

        return false; // Target not found
    }
};
