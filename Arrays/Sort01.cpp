#include <iostream>
using namespace std;

// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

int main()
{
    int arr[25] = {1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        if (arr[i] == 0 && arr[j] == 1)
        {
            i++;
            j--;
        }
        else if (arr[i] == 0 && arr[j] == 0)

        {
            i++;
        }
        else if (arr[i] == 1 && arr[j] == 0)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        else if (arr[i] == 1 && arr[j] == 1)
        {
            j--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}