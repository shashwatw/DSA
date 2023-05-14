#include <iostream>
using namespace std;

bool binarySearch(int *arr, int l, int h, int key)
{
    if (l > h)
    {
        return false;
    }

    int mid = l + (h - l) / 2;

    if (arr[mid] == key)
    {
        return true;
    }
    else if (arr[mid] > key)
    {
        return binarySearch(arr, l, mid - 1, key);
    }
    else
    {
        return binarySearch(arr, mid + 1, h, key);
    }
}

int main()
{

    int arr[] = {3, 5, 2, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 8;

    bool ans = binarySearch(arr, 0, n - 1, key);

    if (ans == true)
    {
        cout << "Element is present";
    }
    else
    {
        cout << "Element is not present";
    }

    return 0;
}