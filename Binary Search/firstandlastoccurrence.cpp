#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int key)
{
    int l = 0;
    int h = n - 1;
    int res = -1;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (arr[mid] == key)
        {
            res = mid;
            h = mid - 1;
        }
        else if (arr[mid] > key)
        {
            h = mid - 1;
        }
        else if (arr[mid] < key)
        {
            l = mid + 1;
        }
    }

    return res;
}

int lastOccurrence(int arr[], int n, int key)
{
    int l = 0;
    int h = n - 1;
    int res = -1;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (arr[mid] == key)
        {
            res = mid;
            l = mid + 1;
        }
        else if (arr[mid] > key)
        {
            h = mid - 1;
        }
        else if (arr[mid] < key)
        {
            l = mid + 1;
        }
    }

    return res;
}

int main()
{

    int even[21] = {2, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 10, 12};

    cout << "Index of First Occurrence: " << firstOccurrence(even, 21, 5) << endl;
    cout << "Index of Last Occurrence: " << lastOccurrence(even, 21, 5) << endl;

    return 0;
}