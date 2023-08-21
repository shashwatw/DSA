//https://leetcode.com/problems/majority-element/description/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() == 1)
        {
            return nums[0];
        }
        int count = 0;
        for(int i = 0; i<nums.size() ; i++)
        {
            if(nums[i]==nums[i+1])
            {
                count++;
                if(count >= (nums.size()-1)/2)
                {
                    return nums[i];
                }
            }
            else
            {
                count = 0;
            }
        }
        return 1;
    }
};