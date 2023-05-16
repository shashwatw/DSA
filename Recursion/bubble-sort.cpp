#include <iostream>
using namespace std;

void sortArray(int *arr, int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
    sortArray(arr, n - 1);
}

int main()
{
    int arr[] = {2, 5, 1, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    sortArray(arr, n);

    cout << "\nSorted array is:   ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}