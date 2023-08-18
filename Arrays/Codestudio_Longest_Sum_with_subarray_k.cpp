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
