// https://www.naukri.com/code360/problems/build-min-heap_1171167

#include <bits/stdc++.h>

void heapify(vector<int> &arr, int n, int i)
{
    int smallest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < n && arr[smallest] > arr[leftChild])
    {
        smallest = leftChild;
    }

    if (rightChild < n && arr[smallest] > arr[rightChild])
    {
        smallest = rightChild;
    }

    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    return arr;
}
