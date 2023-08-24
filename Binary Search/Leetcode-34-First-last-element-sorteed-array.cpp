//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int n = nums.size();
        int h = n - 1;
        vector<int> ans;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (target > nums[mid]) {
                l = mid + 1;
            } else if (target < nums[mid]) {
                h = mid - 1;
            } else {
                // Extend the search to the left and right of mid to find the range
                int left = mid;
                int right = mid;

                while (left > 0 && nums[left - 1] == target) {
                    left--;
                }

                while (right < n - 1 && nums[right + 1] == target) {
                    right++;
                }

                ans.push_back(left);
                ans.push_back(right);
                return ans;
            }
        }
        
        ans.push_back(-1);  // Target not found
        ans.push_back(-1);
        return ans;
    }
};
