//* https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/

class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        int i = 0;

        long sum = 0;
        for (auto it : chalk)
        {
            sum += it;
        }

        k = k % sum;

        while (k > 0)
        {
            k = k - chalk[i];
            if (k < 0)
            {
                return i;
            }
            i++;
        }
        return i;
    }
};