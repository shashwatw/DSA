#include <iostream>
using namespace std;

int isSorted(int arr[], int n)
{
    if (n == 0 | n == 1)
    {
        return true;
    }
    else
    {
        if (arr[0] > arr[1])
        {
            return false;
        }
        else
        {
            bool remainingArray = isSorted(arr + 1, n - 1);
            return remainingArray;
        }
    }
}

int main()
{
    int arr[] = {1, 2, 9, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    bool ans = isSorted(arr, n);

    if (ans == true)
    {
        cout << "Array is sorted";
    }
    else
    {
        cout << "Array is not sorted";
    }

    return 0;
}