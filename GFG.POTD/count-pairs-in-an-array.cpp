// https://www.geeksforgeeks.org/problems/count-pairs-in-an-array4145/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int cnt = 0;

    void merge(vector<int> &arr2, int low, int mid, int high)
    {
        int left = low;
        int right = mid + 1;
        vector<int> temp;

        while (left <= mid && right <= high)
        {
            if (arr2[left] > arr2[right])
            {
                cnt += (mid - left + 1);
                temp.push_back(arr2[right++]);
            }
            else
            {
                temp.push_back(arr2[left++]);
            }
        }

        while (left <= mid)
        {
            temp.push_back(arr2[left++]);
        }

        while (right <= high)
        {
            temp.push_back(arr2[right++]);
        }

        for (int i = low; i <= high; i++)
        {
            arr2[i] = temp[i - low];
        }
    }

    void mergeSort(vector<int> &arr2, int low, int high)
    {
        if (low >= high)
            return;

        int mid = low + (high - low) / 2;

        mergeSort(arr2, low, mid);
        mergeSort(arr2, mid + 1, high);
        merge(arr2, low, mid, high);
    }

    int countPairs(int arr[], int n)
    {
        // Your code goes here
        vector<int> arr2(n);

        for (int i = 0; i < n; i++)
        {
            arr2[i] = i * arr[i];
        }

        mergeSort(arr2, 0, n - 1);
        return cnt;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.countPairs(a, n) << endl;
    }
}
// } Driver Code Ends