//https://leetcode.com/problems/single-element-in-a-sorted-array/description/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n - 1;

        while (l < h) {
            int mid = l + (h - l) / 2;
            
            if (mid % 2 == 1) { // Ensure mid is at even index
                mid--;
            }
            
            if (nums[mid] == nums[mid + 1]) {
                l = mid + 2;
            } else {
                h = mid;
            }
        }
        
        return nums[l];
    }
};
