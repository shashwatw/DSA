//https://leetcode.com/problems/sort-characters-by-frequency/description/

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mpp;

        // Count character frequency
        for (char c : s) {
            mpp[c]++;
        }

        // Custom comparison function for sorting by character frequency
        auto compare = [&mpp](char a, char b) {
            if (mpp[a] == mpp[b]) {
                return a < b; // If frequency is the same, sort lexicographically
            }
            return mpp[a] > mpp[b];
        };

        // Sort characters based on frequency
        sort(s.begin(), s.end(), compare);

        return s;
    }
};