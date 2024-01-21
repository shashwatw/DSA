// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-sorting/problem/merge-sort

//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
public:
    void merge(int arr[], int l, int m, int r)
    {
        if (l == r)
            return;
        int left = l;
        int right = m + 1;
        int temp[r - l + 1];
        int ind = 0;
        while (left <= m && right <= r)
        {
            if (arr[left] <= arr[right])
            {
                temp[ind++] = arr[left++];
            }
            else
            {
                temp[ind++] = arr[right++];
            }
        }
        while (left <= m)
        {
            temp[ind++] = arr[left++];
        }
        while (right <= r)
        {
            temp[ind++] = arr[right++];
        }
        ind = 0;
        for (int i = l; i <= r; i++)
        {
            arr[i] = temp[ind++];
        }
        return;
    }

public:
    void mergeSort(int arr[], int l, int r)
    {
        if (l >= r)
            return;
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
};

//{ Driver Code Starts.

int main()
{
    int n, T, i;

    scanf("%d", &T);

    while (T--)
    {

        scanf("%d", &n);
        int arr[n + 1];
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        Solution ob;
        ob.mergeSort(arr, 0, n - 1);
        printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends