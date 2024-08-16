//* https://leetcode.com/problems/maximum-distance-in-arrays/

class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int result = 0;
        int min_val = arrays[0].front();
        int max_val = arrays[0].back();

        for (int i = 1; i < arrays.size(); ++i)
        {
            // Calculate distances for the current array
            result = max(result, max(abs(arrays[i].back() - min_val), abs(max_val - arrays[i].front())));

            // Update min_val and max_val
            min_val = min(min_val, arrays[i].front());
            max_val = max(max_val, arrays[i].back());
        }

        return result;
    }
};
