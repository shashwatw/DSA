//https://leetcode.com/problems/single-number/description/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int s = 0;
        int l = 1;

        if(n == 1)
        {
            return nums[0];
        }
        for(int i = 0; i< n; i++)
        {
            if(nums[s] == nums[l])
            {
                s+=2;
                l+=2;
            }
            else
            {
                break;
            }
        }
        return nums[s];
    }
};