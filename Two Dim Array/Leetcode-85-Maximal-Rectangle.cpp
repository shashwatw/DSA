// https://leetcode.com/problems/maximal-rectangle/description/

class Solution
{
public:
    int largestRectangleArea(vector<int> heights)
    {
        stack<int> st;
        int maxA = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
            {
                int height = heights[st.top()];
                st.pop();

                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                maxA = max(maxA, height * width);
            }
            st.push(i);
        }
        return maxA;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int maxArea = 0;
        vector<int> heights(cols, 0);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < heights.size(); j++)
            {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            int area = largestRectangleArea(heights);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};