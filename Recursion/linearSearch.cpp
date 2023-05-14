#include <iostream>
using namespace std;

bool linearSearch(int *arr, int n, int k)
{
    if (n == 0)
    {
        return false;
    }
    if (arr[0] == k)
    {
        return true;
    }
    else
    {
        bool remainingArray = linearSearch(arr + 1, n - 1, k);
        return remainingArray;
    }
}

int main()
{

    int arr[] = {3, 2, 5, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 9;

    bool ans = linearSearch(arr, n, k);

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