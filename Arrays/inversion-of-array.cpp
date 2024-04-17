// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long cnt = 0;
    void merge(long long arr[], int low, int mid, int high)
    {
        vector<long long> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left++]);
            }
            // right is smaller
            else
            {
                temp.push_back(arr[right++]);
                cnt += (mid - left + 1);
            }
        }

        while (left <= mid)
        {
            temp.push_back(arr[left++]);
        }

        while (right <= high)
        {
            temp.push_back(arr[right++]);
        }

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
    }

    void mergeSort(long long arr[], int low, int high)
    {
        if (low >= high)
            return;

        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }

    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        mergeSort(arr, 0, N - 1);
        return cnt;
    }
};

//{ Driver Code Starts.

int main()
{

    long long T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends