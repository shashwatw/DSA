//* https://www.geeksforgeeks.org/problems/rectangles-in-a-circle0457/1

// User function Template for C++

class Solution
{
public:
    int rectanglesInCircle(int r)
    {
        int diameter = r << 1;
        int diameterSquare = diameter * diameter;

        int rectanglesCount = 0;
        int left = 1;
        int right = diameter;

        while (left < diameter && right >= 1)
        {
            if ((left * left) + (right * right) <= diameterSquare)
            {
                rectanglesCount += right;
                left++;
            }
            else
            {
                right--;
            }
        }
        return rectanglesCount;
    }
};