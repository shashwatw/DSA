#include <iostream>
using namespace std;

int calSum(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return arr[0];
    }
    else
    {
        int sum = arr[0] + calSum(arr + 1, n - 1);
        return sum;
    }
}

int main()
{

    int arr[] = {3, 2, 5, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int ans = calSum(arr, n);

    cout << ans;

    return 0;
}