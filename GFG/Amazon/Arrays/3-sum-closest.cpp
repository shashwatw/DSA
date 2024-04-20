// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/three-sum-closest

//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution
{
public:
    int threeSumClosest(vector<int> &arr, int target)
    {
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int closestSum = arr[0] + arr[1] + arr[2];

        for (int i = 0; i < n - 2; i++)
        {
            int left = i + 1;
            int right = n - 1;

            while (left < right)
            {
                int currentSum = arr[i] + arr[left] + arr[right];

                if (abs(currentSum - target) < abs(closestSum - target) || (abs(currentSum - target) == abs(closestSum - target) && currentSum >= closestSum))
                {
                    closestSum = currentSum;
                }

                if (currentSum < target)
                {
                    left++;
                }
                else if (currentSum > target)
                {
                    right--;
                }
                else
                {
                    return currentSum;
                }
            }
        }

        return closestSum;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, target;
        cin >> n >> target;

        vector<int> vec(n);

        for (int i = 0; i < n; ++i)
            cin >> vec[i];
        Solution obj;
        cout << obj.threeSumClosest(vec, target) << "\n";
    }
}

// Position this line where user code will be pasted.

// } Driver Code Ends