#include <iostream>
using namespace std;
int main()
{
    int arr[25] = {1, 0, 0, 0, 2, 0, 1, 2, 0, 1, 0, 2, 0, 2, 0, 2, 0, 1, 0, 1, 2, 2, 1, 2, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    int i = 0;
    int j = n - 1;
    int k = 0;

    while (k <= j)
    {
        if (arr[k] == 0)
        {
            int temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
            i++;
            k++;
        }
        else if (arr[k] == 1)
        {
            k++;
        }
        else if (arr[k] == 2)
        {
            int temp = arr[j];
            arr[j] = arr[k];
            arr[k] = temp;
            j--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}