//https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_6682399?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

/*
    Time Complexity: O( N^2 ) 
    Space Complexity: O(1)

    where N is the size of array 'A'.
*/
int longestSubarrayWithSumK(vector < int > a, long long k) {

    int n = a.size();
    // maxLength is used to store the maximum 
    // length of a subarray whose sum = 'k'
    
    int maxLength = 0;

    // Iterating over 'a'
    for (int i = 0; i < n; ++i) {
        long long currentSum = 0;
        for(int j = i; j < n; ++j) {
            currentSum += a[j];

            if(currentSum == k) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }

    return maxLength;
}


//O(n) app
#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){

unordered_map<long long, int> prefixSum;  // Stores prefix sum and its index
    int maxLength = 0;
    long long sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        if (sum == k) {
            maxLength = i + 1;  // Subarray from index 0 to i has sum k
        }

        if (prefixSum.find(sum - k) != prefixSum.end()) {
            maxLength = max(maxLength, i - prefixSum[sum - k]);
        }

        // Store the current prefix sum only if it's not already in the map
        if (prefixSum.find(sum) == prefixSum.end()) {
            prefixSum[sum] = i;
        }
    }

    return maxLength;
}