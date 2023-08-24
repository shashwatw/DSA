//https://leetcode.com/problems/find-peak-element/description/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n - 1;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if ((mid == 0 || nums[mid] > nums[mid - 1]) &&
                (mid == n - 1 || nums[mid] > nums[mid + 1])) {
                return mid; // Found a peak element
            } else if (mid < n - 1 && nums[mid] < nums[mid + 1]) {
                l = mid + 1; // Move to the right side
            } else {
                h = mid - 1; // Move to the left side
            }
        }

        return -1; // Peak element not found (you can choose a different indicator)
    }
};
