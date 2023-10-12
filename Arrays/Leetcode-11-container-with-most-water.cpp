// https://leetcode.com/problems/container-with-most-water/description/

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxarea = 0;
        int cnt = height.size();
        int l = 0;
        int h = cnt - 1;

        while (l < h)
        {
            int width = h - l;
            maxarea = max(maxarea, min(height[l], height[h]) * width);

            if (height[l] <= height[h])
            {
                l++;
            }
            else
            {
                h--;
            }
        }
        return maxarea;
    }
};