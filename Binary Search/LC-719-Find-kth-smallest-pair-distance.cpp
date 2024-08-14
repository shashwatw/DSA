//* https://leetcode.com/problems/find-k-th-smallest-pair-distance
//& Reference : https://youtu.be/hx8Ssz_3XSs?si=64Wqh3HQLJ_Krrot

// 5th Approach - MOST OPTIMAL
class Solution
{
private:
    int slidingWindowCnt(vector<int> &nums, int dist)
    {
        int i = 0;
        int j = 1;
        int n = nums.size();
        int pairCnt = 0;

        while (j < n)
        {
            while (nums[j] - nums[i] > dist)
            {
                i++;
            }

            pairCnt += (j - i);
            j++;
        }
        return pairCnt;
    }

public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int l = 0;
        int h = nums[n - 1] - nums[0]; // highest dist possible

        int result = 0;

        while (l <= h)
        {
            int mid = l + (h - l) / 2;

            int countPairs = slidingWindowCnt(nums, mid);

            if (countPairs < k)
            {
                l = mid + 1;
            }
            else
            {
                result = mid;
                h = mid - 1;
            }
        }
        return result;
    }
};

// 1st Approach - BRUTE FORCE

// class Solution {
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         int low = 0, high = nums[n - 1] - nums[0];

//         while (low < high) {
//             int mid = low + (high - low) / 2;
//             int count = 0, left = 0;

//             for (int right = 0; right < n; ++right) {
//                 while (nums[right] - nums[left] > mid) {
//                     left++;
//                 }
//                 count += right - left;
//             }

//             if (count >= k) {
//                 high = mid;
//             } else {
//                 low = mid + 1;
//             }
//         }

//         return low;
//     }
// };

// 2 Approach - creating a k size max Heap and pushing diff into it...finally top element of heap would be our kth smallest

// 3 Approach- using an array

// class Solution {
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
//         int n = nums.size();
//         int maxEl = *max_element(nums.begin(), nums.end());
//         vector<int> arr(maxEl+1, 0);

//         //incrementing count at arr's posn where difference is of arr's index
//         for(int i = 0; i < n; i++) {
//             for(int j = i+1; j < n; j++) {
//                 int d = abs(nums[i] - nums[j]);
//                 arr[d]++;
//             }
//         }

//         for(int d = 0; d < arr.size(); d++) {
//             k -= arr[d];
//             if(k <= 0) {
//                 return d;
//             }
//         }

//         return -1;
//     }
// };

// 4th Approach - Nth element utility (only in c++)
//  nth_element(begin(vec), begin(vec)+(k-1), end(vec)) is format of this func
//  Normal sorting takes nlogn but this will give us exactly nth element with doing partial sort and return us nth element in optimal time --- > Therefore avg TC of nth_element is O(n) but worst is O(n);

// So now we will create a vector which would have size = num of all combinations and contains difference of combinations inside vec
// Traditional sort would have taken nlogn as avg TC but nth_element will take O(n) as avg TC

// class Solution {
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
//         vector<int> allDiff;
//         for(int i = 0; i < nums.size(); i++) {
//             for(int j = i+1; j < nums.size(); j++) {
//                 int d = abs(nums[i] - nums[j]);
//                 allDiff.push_back(d);
//             }
//         }

//         nth_element(begin(allDiff), begin(allDiff)+(k-1), end(allDiff));
//         return allDiff[k-1];
//     }
// };
