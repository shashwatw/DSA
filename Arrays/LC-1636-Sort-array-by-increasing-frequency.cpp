//^ https://leetcode.com/problems/sort-array-by-increasing-frequency/description/

class Solution
{
private:
    class Compare
    {
    public:
        bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b)
        {
            if (a.second != b.second)
                return a.second < b.second;
            return a.first > b.first;
        }
    };

public:
    vector<int> frequencySort(vector<int> &nums)
    {
        // Step 1: Count the frequency of each number
        unordered_map<int, int> freq;
        for (int num : nums)
        {
            freq[num]++;
        }

        // Step 2: Create a vector of pairs ---> (number, frequency)
        vector<pair<int, int>> freqPairs;
        for (auto &it : freq)
        {
            freqPairs.push_back(it);
        }

        // Step 3: Sort the pairs
        sort(freqPairs.begin(), freqPairs.end(), Compare());

        // Step 4: Compute the result based on sorted pairs
        vector<int> result;
        for (auto &p : freqPairs)
        {
            result.insert(result.end(), p.second, p.first);
        }

        return result;
    }
};
