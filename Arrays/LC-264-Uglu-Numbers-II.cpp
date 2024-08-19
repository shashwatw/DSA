//* https://leetcode.com/problems/ugly-number-ii/description/

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> uglyNums{1};
        int list2 = 0;
        int list3 = 0;
        int list5 = 0;

        while (uglyNums.size() < n)
        {
            int n2 = uglyNums[list2] * 2;
            int n3 = uglyNums[list3] * 3;
            int n5 = uglyNums[list5] * 5;

            int minimum = min(n2, min(n3, n5));

            if (minimum == n2)
            {
                list2++;
            }
            if (minimum == n3)
            {
                list3++;
            }
            if (minimum == n5)
            {
                list5++;
            }

            uglyNums.push_back(minimum);
        }
        return uglyNums.back();
    }
};