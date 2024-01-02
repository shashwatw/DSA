// https://leetcode.com/problems/3sum/description/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0)
                {
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    ans.push_back(temp);
                    left++;
                    right--;

                    // Ignore duplicate values for the second element
                    while (left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }

                    // Ignore duplicate values for the third element
                    while (left < right && nums[right] == nums[right + 1])
                    {
                        right--;
                    }
                }
                else if (sum < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            {
                i++;
            }
        }
        return ans;
    }
};