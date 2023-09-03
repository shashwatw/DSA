//https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        if(nums.empty())
        {
            return 0;
        }

        int count = 0;
        for(int i = 1; i < nums.size() ; i++)
        {
            if(nums[i]!=nums[i-1])
            {
                count = 0;
                nums[k] = nums[i];
                k++;
            }
            else
            {
                if(nums[i]==nums[i-1])
                {
                    count++;
                    if(count < 2)
                    {
                        nums[k] = nums[i];
                        k++;
                    }
                }
            }
        }
        return k;
        
    }
};